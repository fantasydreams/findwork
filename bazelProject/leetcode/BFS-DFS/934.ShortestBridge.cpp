#include "934.ShortestBridge.h"
#include <queue>
using namespace std;

void BFS(vector<vector<int>> & grid, int x, int y, queue<pair<int, int>> & _queue)
{
    static vector<int> direction = {-1, 0, 1, 0, -1};
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size() || grid[x][y] == 2) {
        return;
    }

    if(grid[x][y] == 0)
    {
        _queue.push({x, y});
        return;
    }

    grid[x][y] = 2;
    for(int i = 0; i < 4; ++i)
    {
        int nextx = x + direction[i];
        int nexty = y + direction[i + 1];
        BFS(grid, nextx, nexty, _queue);
    }
}

int shortestBridge(vector<vector<int>>& grid)
{
    if(grid.size() == 0) {
        return 0;
    }
    bool fliped = false;
    queue<pair<int, int>> _queue;
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; (i < m) && !fliped; ++i)
    {
        for(int j = 0; (j < n) && !fliped; ++j)
        {
            if(grid[i][j] == 0) {
                continue;
            }
            BFS(grid, i, j, _queue);
            fliped = true;
        }
    }

    int level = 0;
    vector<int> direction = {-1, 0, 1, 0, -1};
    while(!_queue.empty())
    {
        ++level;
        int size = _queue.size();
        while(size--)
        {
            auto [x, y] = _queue.front();
            _queue.pop();

            printf("%d %d %d\n\n", x, y, grid[x][y]);
            for(int i = 0; i < 4; ++i)
            {
                int nextx = x + direction[i];
                int nexty = y + direction[i + 1];
                if(nextx < 0 || nexty < 0 || nextx >= m || nexty >= n || grid[nextx][nexty] == 2){
                    continue;
                }

                if(grid[nextx][nexty] == 1) {
                    return level;
                }
                
                _queue.push({nextx, nexty});
                grid[nextx][nexty] = 2;
            }
        }
    }
    return level;
}