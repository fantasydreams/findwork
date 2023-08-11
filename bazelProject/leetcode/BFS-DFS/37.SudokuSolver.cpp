#include "37.SudokuSolver.h"

bool Sudoku(const vector<vector<char>>& board, int row, int col, char ch)
{
    for(int k = 0; k < 9; ++k)
    {
        if(board[row][k] == ch) {
            return false;
        }
        if(board[k][col] == ch) {
            return false;
        }
        if(board[(row / 3) * 3 + (k / 3)][(col / 3) * 3 + k % 3] == ch){
            return false;
        }
    }
    return true;
}

bool solver(vector<vector<char>>& board)
{
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            if(board[i][j] == '.')
            {
                for(char ch = '1'; ch <= '9'; ++ch)
                {
                    if(Sudoku(board, i, j, ch) == true) 
                    {
                        board[i][j] = ch;
                        if(solver(board)) {
                            return true;
                        }else {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board)
{
    solver(board);
}


bool validSudu(vector<vector<char> >& board, int r, int c, char ch) {
    for(int i = 0; i < board.size(); ++i) {
        if(board[r][i] == ch || board[i][c] == ch) {
            return false;
        }

        if(board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) { // 为什么呢？ :
            return false;
        }
    }
    return true;
}


int solver1(vector<vector<char> >& board) {
    int n = board.size();
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < n; ++c) {
            if(board[r][c] == '.') {
                for(char ch = '1'; ch <= '9'; ++ch) {
                    if(validSudu(board, r, c, ch)) {
                        board[r][c] = ch;
                        if(solver1(board)) {
                            return true;
                        }else {
                            board[r][c] = '.';
                        }
                    }
                }
                return false;
            }

        }
    }
    return true;
}


void solveSudoku1(vector<vector<char> >& board)
{
    solver1(board);
}