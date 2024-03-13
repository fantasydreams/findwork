#include "64.MinimumPathSum.h"

int getminpathsum(const vector<vector<int>>& grid, int x, int y)
{
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size()) {
        return 0;
    }
    if(x == 0 && y == 0) {
        return grid[x][y];
    }
    if(x == 0) {
        return getminpathsum(grid, x, y - 1) + grid[x][y];
    }else if(y == 0) {
        return getminpathsum(grid, x - 1, y) + grid[x][y];
    }

    return min(getminpathsum(grid, x - 1, y), getminpathsum(grid, x, y - 1)) + grid[x][y];
}

int minPathSum(vector<vector<int>>& grid)
{
    if(grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }

    return getminpathsum(grid, grid.size() - 1, grid[0].size() - 1);
}

//使用dp记录已经计算过的，避免递归重复计算
int minPathSum1(vector<vector<int>>& grid)
{
    if(grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }

    std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size()));
    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[i].size(); ++j)
        {
            if(i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            }else if(i == 0) {
                dp[i][j] = dp[i][j-1] + grid[i][j];
            }else if(j == 0) {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }else
            {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
    }

    return dp[grid.size()-1][grid[0].size()-1];
}

// dp空间压缩, 行更行dp[j] 可以表示为dp[i-1][j], dp[j-1] 可以表示为 dp[i][j-1]
int minPathSum2(vector<vector<int>>& grid)
{
    if(grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }

    std::vector<int> dp(grid[0].size(), 0);
    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[i].size(); ++j)
        {
            if(i == 0 && j == 0) {
                dp[j] = grid[i][j];
            }else if(i == 0) {
                dp[j] = dp[j-1] + grid[i][j];
            }else if(j == 0) {
                dp[j] = dp[j] + grid[i][j];
            }else {
                dp[j] = std::min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
    }

    return dp[grid[0].size()-1];
}


int minPathSumDp(vector<vector<int> >& grid) {
    if(grid.empty() || grid[0].empty()) {
        return 0;
    }

    std::vector<std::vector<int> > dp(grid.size(), std::vector<int>(grid[0].size(), 0));
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            }else if(i == 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }else if(j == 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }else {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }

    return dp[grid.size() - 1][grid[0].size() - 1];
}

int minPathSumDpCompress(vector<vector<int> >& grid) {
    if(grid.empty() || grid[0].empty()) {
        return 0;
    }

    std::vector<int> dp(grid[0].size(),0);
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(i == 0 && j == 0) {
                dp[j] = grid[i][j];
            }else if(i == 0) {
                dp[j] = dp[j - 1] + grid[i][j];
            }else if(j == 0) {
                dp[j] = dp[j] + grid[i][j];
            }else {
                dp[j] = std::min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
    } 

    return dp[grid[0].size() - 1];
}


int minPathSumDp1(vector<vector<int> >& grid) {
    if(grid.empty() || grid[0].empty()) {
        return 0;
    }

    std::vector<std::vector<int> > dp(grid.size(), std::vector<int>(grid[0].size(), INT_MAX));
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            }else if(i == 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }else if(j == 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }else {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }

    return dp.back().back();
}


int minPathSumDpCompress1(vector<vector<int> >& grid) {
    if(grid.empty() || grid[0].empty()) {
        return 0;
    }

    std::vector<int> dp(grid[0].size(), 0);
    for(int i = 0; i < grid.size(); ++ i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(i == 0 && j == 0) {
                dp[j] = grid[i][j];
            }else if(i == 0) {
                dp[j] = dp[j - 1] + grid[i][j];
            }else if(j == 0) {
                dp[j] = dp[j] + grid[i][j];
            }else {
                dp[j] = std::min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
    }

    return dp.back();
}