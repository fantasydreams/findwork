#include "695.MaxAreaofIsland.h"
#include <cmath>
#include <queue>
#include <stack>


void BFS(const vector<vector<int>>& grid, int x, int y, vector<vector<bool>> & record, int & _max)
{
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
        return;
    }

    if(grid[x][y] == 0 || record[x][y]) {
        return;
    }

    _max += 1;
    record[x][y] = true;
    BFS(grid, x - 1, y, record, _max);
    BFS(grid, x, y + 1, record, _max);
    BFS(grid, x, y - 1, record, _max);
    BFS(grid, x + 1, y, record, _max);
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int _max = 0;
    if(grid.size() == 0) {
        return _max;
    }

    vector<vector<bool>> record(grid.size(), std::vector<bool>(grid[0].size(), false));
    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[i].size(); ++j)
        {
            if(grid[i][j] && !record[i][j]) 
            {
                int tmp = 0;
                BFS(grid, i, j, record, tmp);
                _max = max(_max, tmp);
            }
        }
    }
    
    return _max;
}

// 使用栈或者队列代替 递归
int maxAreaOfIsland1(vector<vector<int>>& grid)
{
    int _max = 0, _tmpmax = 0;
    std::vector<int> direction = {-1, 0, 1, 0, -1};
    std::stack<std::pair<int, int>> _stack;
    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[i].size(); ++j)
        {
            if(grid[i][j])
            {
                _tmpmax = 1;
                grid[i][j] = 0;
                _stack.push({i, j});
                while(!_stack.empty())
                {
                    auto [x, y] = _stack.top();
                    _stack.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int nextx = x + direction[k];
                        int nexty = y + direction[k + 1];
                        if(nextx < 0 ||  nextx >= grid.size() || nexty < 0 || nexty >= grid[nextx].size()) {
                            continue;
                        }
                        
                        if(grid[nextx][nexty]) 
                        {
                            _tmpmax += 1;
                            grid[nextx][nexty] = 0;
                            _stack.push({nextx, nexty});
                        }
                    }
                }
                _max = std::max(_max, _tmpmax);
            }
        }
    }

    return _max;
}