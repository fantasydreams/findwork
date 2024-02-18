#include "909.SnakesandLadders.h"
#include <queue>

inline int getRow(int next, int n) {
    return (n - 1) - (next - 1) / n;
}

inline int getCol(int next, int n) {
    return ((next - 1) / n) % 2 == 0 ? (next - 1) % n : (n - 1) - ((next - 1) % n);
}

int snakesAndLadders(vector<vector<int> >& board) {
    if(board.size() == 0 || board.size() == 1) {
        return 0;
    }
    
    int iAns = 0, n = board.size();
    std::queue<int> que; que.push(1);
    std::vector<bool> visited(n * n, false);
    visited[0] = true;
    while(!que.empty()) {
        int iSize = que.size();
        ++iAns;
        while(iSize--) {
            int iCur = que.front(); que.pop();
            for(int i = 1; i <= 6; ++i) {
                int next = iCur + i;
                if(next > n * n) {
                    break;
                }

                int nextRow = getRow(next, n);
                int nextCol = getCol(next, n);
                if(board[nextRow][nextCol] != -1) {
                    next = board[nextRow][nextCol];
                }

                if(next == n * n) {
                    return iAns;
                }

                if(visited[next - 1] == false) {
                    visited[next - 1] = true;
                    que.push(next);
                }
            }
        }
    }

    return -1;
}