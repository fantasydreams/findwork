#include "36.ValidSudoku.h"
#include <cstdlib>
#include <type_traits>
#include <vector>

bool isValidSudoku(vector<vector<char> >& board) {
    // 行
    if(board.size() == 0 || board[0].size() == 0) {
        return true;
    }

    for(const auto & line : board) {
        std::vector<bool> tmp(line.size(), false);
        for(const auto& i : line) {
            if(i != '.') {
                int num = i - '1';
                if(tmp[num]) {
                    return false;
                }
                tmp[num] = true;
            }
        }
    }

    //列
    for(int i = 0; i < board[0].size(); ++i) {
        std::vector<bool> tmp(board.size(), false);
        for(int j = 0; j < board.size(); ++j) {
            if(board[j][i] != '.') {
                int num = board[j][i] - '1';
                if(tmp[num]) {
                    return false;
                }
                tmp[num] = true;
            }
        }
    }

    //九宫格
    for(int r = 0; r < 3; ++r) {
        for(int c = 0; c < 3; ++c) {
            std::vector<bool> tmp(board.size(), false);
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    int row = r * 3 + i, col = c * 3 + j;
                    if(board[row][col] != '.') {
                        int num = board[row][col] - '1';
                        // printf("%d %d %d\n",row, col, num);
                        if(tmp[num]) {
                            return false;
                        }
                        tmp[num] = true;
                    }
                }
            }

            // printf("\n");
        }
    }

    return true;
}

bool isValidSudoku1(vector<vector<char> >& board) {
    std::vector<std::vector<bool> > row(board.size(), std::vector<bool> (board.size(),false));
    std::vector<std::vector<bool> > col = row;
    std::vector<std::vector<bool> > block = row;

    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board.size(); ++j) {
            if(board[i][j] == '.') {
                continue;
            }

            int num = board[i][j] - '1';
            if(row[i][num] || col[j][num] || block[(i / 3) * 3 + (j / 3)][num]) {
                return false;
            }
            
            row[i][num] = col[j][num] = block[(i / 3) * 3 + (j / 3)][num] = true;
        }
    }

    return true;
}


bool isValidSudoku2(vector<vector<char> > &board) {
    std::vector<std::vector<bool> > row(board.size(), std::vector<bool>(9, false));
    std::vector<std::vector<bool> > col = row, block = row;
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board.size(); ++j) {
            if(board[i][j] == '.') {
                continue;
            }

            int num = board[i][j] - '1';
            if(row[i][num] || col[j][num] || block[i/3 * 3 + j / 3][num]) {
                return false;
            }
            row[i][num] = col[j][num] = block[i/3 * 3 + j / 3][num] = true;
        }
    }

    return true;
}