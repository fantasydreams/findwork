#include "417.PacificAtlanticWaterFlow.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<vector<int>> grid = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};
    EXPECT_EQ(pacificAtlantic(grid), res);
}

TEST(case_2,content)
{
    vector<vector<int>> grid = {{1}};
    vector<vector<int>> res = {{0,0}};
    EXPECT_EQ(pacificAtlantic(grid), res);
}

TEST(case_3,content)
{
    vector<vector<int>> grid = {{3,3,3,3,3,3},{3,0,3,3,0,3},{3,3,3,3,3,3}};
    vector<vector<int>> res = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 0, 5 }, { 1, 0 }, { 1, 2 }, { 1, 3 }, { 1, 5 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 }, { 2, 5 } };
    EXPECT_EQ(pacificAtlantic(grid), res);
}
