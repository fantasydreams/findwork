#include "174.DungeonGame.h"
#include <algorithm>
#include <climits>


void DFS(const vector<vector<int> >& dungeon, int row, int col, int cur, int path_min, int& min) {
    if(row >= dungeon.size() || col >= dungeon[row].size()) {
        return;
    }

    cur += dungeon[row][col];
    path_min = std::min(path_min, cur);
    if(row == dungeon.size() - 1 && col == dungeon[row].size() - 1) {
        min = std::min(min, abs(path_min) + 1);
        return;
    }

    DFS(dungeon, row, col + 1, cur, path_min, min);
    DFS(dungeon, row + 1, col, cur, path_min, min);
}

int calculateMinimumHP(vector<vector<int> >& dungeon) {
    int min = INT_MAX, cur = 0, path_min = 0;
    DFS(dungeon, 0, 0, cur, path_min, min);
    return min; 
}


// https://soloveri.gitbook.io/leetcode/dynamic-programming/174-dungeon-game
int calculateMinimumHPDp(vector<vector<int> >& dungeon) {
    int M = dungeon.size() - 1, N = dungeon[0].size() - 1;
    std::vector<std::vector<int> >dp(dungeon.size(), std::vector<int>(dungeon[0].size()));
    dp[M][N] = dungeon[M][N] < 0 ? 1 - dungeon[M][N] : 1;
    for(int i = M - 1; i >= 0; --i) {
        dp[i][N] = dungeon[i][N] >= dp[i + 1][N] ? 1 : dp[i + 1][N] - dungeon[i][N];
    }

    for(int i = N - 1; i >= 0; --i) {
        dp[M][i] = dungeon[M][i] >= dp[M][i + 1] ? 1 : dp[M][i + 1] - dungeon[M][i];
    }

    for(int row = M - 1; row >= 0; --row) {
        for(int col = N - 1; col >= 0; --col) {
            if(dungeon[row][col] >= 0) {
                if(dungeon[row][col] >= std::min(dp[row + 1][col], dp[row][col + 1])) {
                    dp[row][col] = 1;
                }else {
                    dp[row][col] = std::min(dp[row + 1][col], dp[row][col + 1]) - dungeon[row][col];
                }
            }else {
                dp[row][col] = std::min(dp[row + 1][col], dp[row][col + 1]) - dungeon[row][col];
            }
        }
    }

    return dp[0][0];
}