#include "289.GameofLife.h"

inline int CntCellAliveNums(const vector<vector<int> >& board, int i, int j) {
    int iAns = 0;
    std::vector<int> vecDX = {-1, -1, -1, 0, 0, 1, 1, 1}, vecDY = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int k = 0; k < vecDX.size(); ++k) {
        int iNextX = i + vecDX[k];
        int iNextY = j + vecDY[k];
        if(iNextX < 0 || iNextY < 0 || iNextX >= board.size() || iNextY >= board[iNextX].size()) {
            continue;
        }

        iAns += board[iNextX][iNextY] & 0x1;
    }

    return iAns;
}

void gameOfLife(vector<vector<int> >& board) {
    for(int row = 0; row < board.size(); ++row) {
        for(int col = 0; col < board[row].size(); ++col) {
            int iAliveNum = CntCellAliveNums(board, row, col);
            if(board[row][col] & 0x1) {
                if(iAliveNum >= 2 && iAliveNum <= 3) {
                    board[row][col] = 0b11;
                }
            }else {
                if(iAliveNum == 3) {
                    board[row][col] = 0b10;
                }
            }
        }
    }

    for(int row = 0; row < board.size(); ++row) {
        for(int col = 0l; col < board[0].size(); ++col) {
            board[row][col] >>= 1;
        }
    }
}