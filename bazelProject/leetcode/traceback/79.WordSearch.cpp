#include "79.WordSearch.h"

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