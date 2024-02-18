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

void DFS1(const vector<vector<char> >& gird, int row, int col, std::vector<vector<bool> > & visited) {
    if(row < 0 || row >= gird.size() || col < 0 || col >= gird[row].size() || gird[row][col] == '0' || visited[row][col]) {
        return;
    }
    visited[row][col] = true;
    static vector<int> vec = {-1, 0, 1, 0, -1};
    for(int i = 0;i < 4; ++i) {
        int nextRow = row + vec[i];
        int nextCol = col + vec[i + 1];
        DFS1(gird, nextRow, nextCol, visited);
    }
}

int numIslands1(vector<vector<char> >& grid) {
    if(grid.empty() || grid[0].empty()) {
        return 0;
    }

    int ans = 0;
    std::vector<std::vector<bool> > visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    for(int row = 0; row < grid.size(); ++row) {
        for(int col = 0; col < grid[row].size(); ++col) {
            if(grid[row][col] == '1' && !visited[row][col]) {
                ++ans;
                DFS1(grid, row, col, visited);
            }
        }
    }

    return ans;
}