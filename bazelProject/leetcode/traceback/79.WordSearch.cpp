#include "79.WordSearch.h"
#include <vector>

void backtrace(const vector<vector<char>>& board, const string & word, int x, int y, int pos, vector<vector<bool>> & visited, bool & bexsit)
{
    if(pos >= word.size()) {
        bexsit = true;
        return;
    }

    if(bexsit || x < 0 || y < 0 || x >= board.size() || y >= board[x].size() || visited[x][y] || board[x][y] != word[pos]) {
        return;
    }

    visited[x][y] = true;
    static vector<int> direction = {-1, 0, 1, 0, -1};
    for(int i = 0; i < 4 && !bexsit; ++i)
    {
        int nextx = x + direction[i];
        int nexty = y + direction[i + 1];
        backtrace(board, word, nextx, nexty, pos + 1, visited, bexsit);
    }
    visited[x][y] = false;
}

bool exist(vector<vector<char>>& board, string word)
{
    bool bexsit = false;

    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for(int i = 0; i < board.size() && !bexsit; ++i)
    {
        for(int j = 0; j < board[i].size() && !bexsit; ++j) {
            backtrace(board, word, i, j, 0, visited, bexsit);
        }
    }

    return bexsit;
}

void bt(bool & bExsit, std::vector<std::vector<bool> >& vecVisited, std::vector<std::vector<char> >& board, int row, int col, const std::string& sWord, int curPos) {
    if(curPos >= sWord.size()) {
        bExsit = true;
        return;
    }

    if( bExsit || row < 0 || row >= board.size() || col < 0 || col >= board[row].size() || vecVisited[row][col] || board[row][col] != sWord[curPos]) {
        return;
    }

    static std::vector<int> vecDirection = {-1, 0, 1, 0, -1};

    vecVisited[row][col] = true;
    for(int i = 0; i < 4 && !bExsit; ++i) {
        int x = vecDirection[i];
        int y = vecDirection[i + 1];
        bt(bExsit, vecVisited, board, row + x, col + y, sWord, curPos + 1);
    }
    vecVisited[row][col] = false;
}

bool exist1(vector<vector<char> >& board, string word) {
    if(board.empty() || board[0].empty()) {
        return false;
    }

    bool bExsit = false;
    std::vector<std::vector<bool> > vecVisited(board.size(), std::vector<bool>(board[0].size(), false));
    for(int row = 0; row < board.size() && !bExsit; ++row) {
        for(int col = 0; col < board[row].size() && !bExsit; ++col) {
            bt(bExsit, vecVisited, board, row, col, word, 0);
        }
    }

    return bExsit;
}