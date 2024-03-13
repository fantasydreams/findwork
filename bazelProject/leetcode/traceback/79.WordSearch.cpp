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

void traceback(vector<vector<char> >&  board, int row, int col, int idx, const std::string& sWord, bool & bExsit, std::vector<std::vector<bool> >&vecVisited) {
    if(idx >= sWord.size()) {
        bExsit = true;
        return ;
    }

    if(bExsit || row < 0 || row >= board.size() || col < 0 || col >= board[row].size() || vecVisited[row][col] || board[row][col] != sWord[idx]) {
        return ;
    }


    static std::vector<int> vec = {-1, 0, 1, 0, -1};
    vecVisited[row][col] = true;
    for(int i = 0; i < 4 && !bExsit; ++i) {
        int nextx = row + vec[i];
        int nexty = col + vec[i + 1];
        
        traceback(board, nextx, nexty, idx + 1, sWord, bExsit, vecVisited);
    }
    vecVisited[row][col] = false;
}


bool exist2(vector<vector<char> >& board, string word) {
    if(board.empty() || board[0].empty() || board.size() * board[0].size() < word.size() || word.empty()) {
        return false;
    }

    bool bExsit = false;
    std::vector<std::vector<bool> >vecVisited(board.size(), std::vector<bool>(board[0].size(), false));
    for(int row = 0; row < board.size() && !bExsit; ++row) {
        for(int col = 0; col < board[row].size() && !bExsit; ++col) {
            traceback(board, row, col, 0, word, bExsit, vecVisited);
        }
    }

    // printf("%d\n", bExsit);
    return bExsit;
}



void traceback1(vector<vector<char> >&  board, int row, int col, int idx, const std::string& sWord, bool & bExsit, std::vector<std::vector<bool> >&vecVisited) {
    vecVisited[row][col] = true;
    if(idx >= sWord.size()) {
        bExsit = true;
        return ;
    }

    static std::vector<int> vec = {-1, 0, 1, 0, -1};
    for(int i = 0; i < 4 && !bExsit; ++i) {
        int nextx = row + vec[i];
        int nexty = col + vec[i + 1];
        
        if(nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[nextx].size() || vecVisited[nextx][nexty] || board[nextx][nexty] != sWord[idx]) {
            continue ;
        }
        traceback1(board, nextx, nexty, idx + 1, sWord, bExsit, vecVisited);
    }
    vecVisited[row][col] = false;
}


bool exist3(vector<vector<char> >& board, string word) {
    if(board.empty() || board[0].empty() || board.size() * board[0].size() < word.size() || word.empty()) {
        return false;
    }

    bool bExsit = false;
    std::vector<std::vector<bool> >vecVisited(board.size(), std::vector<bool>(board[0].size(), false));
    for(int row = 0; row < board.size() && !bExsit; ++row) {
        for(int col = 0; col < board[row].size() && !bExsit; ++col) {
            if(board[row][col] == word[0]) {
                traceback1(board, row, col, 1, word, bExsit, vecVisited);
            }
        }
    }

    // printf("%d\n", bExsit);
    return bExsit;
}