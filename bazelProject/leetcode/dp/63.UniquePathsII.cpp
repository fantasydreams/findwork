#include "63.UniquePathsII.h"

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    if(obstacleGrid.empty() || obstacleGrid[0].empty()) {
        return 0;
    }

    if(obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size() -1 ][obstacleGrid[0].size() - 1] == 1) {
        return 0;
    }

    vector<vector<int> >dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
    for(int i = 0; i < obstacleGrid.size(); ++i) {
        for(int k = 0; k < obstacleGrid[i].size(); ++k) {
            if(i == 0) {
                dp[i][k] = k == 0 ? 1 : obstacleGrid[i][k] == 0 ? dp[i][k - 1] : 0;
            }else if(k == 0) {
                dp[i][k] = obstacleGrid[i][k] == 0 ? dp[i - 1][k] : 0;
            }else {
                dp[i][k] = obstacleGrid[i][k] == 0 ? dp[i - 1][k] + dp[i][k - 1] : 0; 
            }
        }
    }

    return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}


void DFS(const vector<vector<int> >& obstacleGrid, int r, int c, int& ans) {
    if(r == obstacleGrid.size() - 1 && c == obstacleGrid[r].size() - 1) {
        ++ans;
        return;
    }

    if(r >= obstacleGrid.size() || c >= obstacleGrid[r].size() || obstacleGrid[r][c] == 1) {
        return;
    }

    DFS(obstacleGrid, r + 1, c, ans);    
    DFS(obstacleGrid, r, c + 1, ans);
}

int uniquePathsWithObstaclesDFS(vector<vector<int> >& obstacleGrid) {
    if(obstacleGrid.empty() || obstacleGrid[0].empty()) {
        return 0;
    }
    if(obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) {
        return 0;
    }

    int ans = 0;
    DFS(obstacleGrid, 0, 0, ans);
    return ans;
}

int uniquePathsWithObstacles1(vector<vector<int> >& obstacleGrid) {
    if(obstacleGrid.empty() || obstacleGrid.front().empty()) {
        return 0;
    }

    if(obstacleGrid.front().front() == 1 || obstacleGrid.back().back() == 1) {
        return 0;
    }

    std::vector<std::vector<int> > dp(obstacleGrid.size(), std::vector<int>(obstacleGrid.front().size(), 0));
    for(int i = 0; i < obstacleGrid.size(); ++i) {
        for(int j = 0; j < obstacleGrid[i].size(); ++j) {
            if(i == 0) {
                dp[i][j] = j == 0 ? obstacleGrid[i][j] == 0 : obstacleGrid[i][j] == 0 ? dp[i][j - 1] : 0;
            }else if(j == 0) {
                dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i - 1][j] : 0;
            }else {
                dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i - 1][j] + dp[i][j - 1] : 0;
            }
        }
    }
    
    return dp.back().back();
}