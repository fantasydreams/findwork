#include "200.NumberofIslands.h"
#include <ratio>

void DFS(const vector<vector<char> >& grid, vector<vector<bool> >& visited, int r, int c) {
    if(r < 0 || r >= grid.size() || c >= grid[r].size() || c < 0 || grid[r][c] == '0' || visited[r][c]) {
        return;
    }

    visited[r][c] = true;
    DFS(grid, visited, r + 1, c);
    DFS(grid, visited, r - 1, c);
    DFS(grid, visited, r, c + 1);
    DFS(grid, visited, r, c - 1);
}


int numIslands(vector<vector<char> >& grid) {
    if(grid.empty() || grid[0].empty()) {
        return 0;
    }

    int ans = 0;
    std::vector<std::vector<bool> > visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    for(int r = 0; r < grid.size(); ++r) {
        for(int c = 0; c < grid[r].size(); ++c) {
            if(grid[r][c] == '1' && !visited[r][c]) {
                ++ans;
                DFS(grid, visited, r, c);
            }
        }
    }

    return ans;
}