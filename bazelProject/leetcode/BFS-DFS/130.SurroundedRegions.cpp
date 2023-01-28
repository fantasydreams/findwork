#include "130.SurroundedRegions.h"
#include <vector>
#include <queue>

void BFS(int x, int y, vector<vector<char>>& board)
{
    static vector<int> direction = {-1, 0, 1, 0, -1};
    if(x < 0 || y < 0 || x >= board.size() || y >= board[x].size()) {
        return;
    }

    if(board[x][y] != 'O') {
        return;
    }

    board[x][y] = 'o';
    for(int i = 0; i < 4; ++i)
    {
        int nextx = x + direction[i];
        int nexty = y + direction[i + 1];
        BFS(nextx, nexty, board);
    }
}

void solve(vector<vector<char>>& board)
{
    if(board.size() == 0) {
        return;
    }

    for(int i = 0; i < board[0].size(); ++i)
    {
        if(board[0][i] == 'O') {
            BFS(0, i, board);
        }
        if(board[board.size() - 1][i] == 'O') {
            BFS(board.size() - 1, i, board);
        }
    }

    for(int i = 0; i < board.size(); ++i) 
    {
        if(board[i][0] == 'O'){
            BFS(i, 0, board);
        }
        if(board[i][board[i].size() - 1] == 'O') {
            BFS(i, board[i].size() - 1, board);
        }
    }

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == 'o') {
                board[i][j] = 'O';
            }
        }
    }
}

//使用队列解决
void solve1(vector<vector<char>>& board)
{
    if(board.size() == 0) {
        return;
    }

    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < board[0].size(); ++i)
    {
        if(board[0][i] == 'O') {
            q.push({0, i});
        }
        if(board[board.size() - 1][i] == 'O') {
            q.push({board.size() - 1, i});
        }
    }

    for(int i = 0; i < board.size(); ++i) 
    {
        if(board[i][0] == 'O'){
            q.push({i, 0});
        }
        if(board[i][board[i].size() - 1] == 'O') {
            q.push({i, board[i].size() - 1});
        }
    }

    static vector<int> direction = {-1, 0, 1, 0, -1};
    while(q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        if(board[x][y] == 'O')
        {
            board[x][y] = 'o';
            for(int i = 0; i < 4; ++i)
            {
                int nextx = x + direction[i];
                int nexty = y + direction[i + 1];
                
                if(nextx >= 0 && nexty >= 0 && nextx < board.size() && nexty < board[nextx].size() && board[nextx][nexty] == 'O') {
                    q.push({nextx, nexty});
                }
            }
        }
    }

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == 'o') {
                board[i][j] = 'O';
            }
        }
    }
}