#include "417.PacificAtlanticWaterFlow.h"



void dfs(const vector<vector<int>> & heights, vector<vector<bool>> & reach, int x, int y)
{
    static vector<int> direction = {-1, 0, 1, 0 ,-1};
    if(reach[x][y]) {
        return;
    }
    reach[x][y] = true;
    
    for(int i = 0; i < 4; ++i)
    {
        int nextx = x + direction[i];
        int nexty = y + direction[i + 1];
        if(nextx >= 0 && nextx < heights.size() && nexty >= 0 && nexty < heights[nextx].size() && heights[x][y] <= heights[nextx][nexty]) {
            dfs(heights, reach, nextx, nexty);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
    if(heights.size() == 0) {
        return {};
    }

    vector<vector<bool>> reach_p(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool>> reach_a(heights.size(), vector<bool>(heights[0].size(), false));

    for(int i = 0; i < heights.size(); ++i)
    {
        dfs(heights, reach_p, i, 0);
        dfs(heights, reach_a, i, heights[i].size() - 1);
    }

    for(int i = 0; i < heights[0].size(); ++i) 
    {
        dfs(heights, reach_p, 0, i);
        dfs(heights, reach_a, heights.size() - 1, i);
    }

    vector<vector<int>> vecres;
    for(int i = 0; i < heights.size(); ++i)
    {
        for(int j = 0; j < heights[i].size(); ++j)
        {
            if(reach_a[i][j] && reach_p[i][j]){
                vecres.push_back({i, j});
            }
        }
    }

    return vecres;
}