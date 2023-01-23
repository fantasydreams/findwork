#include "934.ShortestBridge.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<vector<int>> grid = {{0,1},{1,0}};
    int res = 1;
    EXPECT_EQ(shortestBridge(grid), res);
}

TEST(case_2,content)
{
    vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
    int res = 2;
    EXPECT_EQ(shortestBridge(grid), res);
}

TEST(case_3,content)
{
    vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    int res = 1;
    EXPECT_EQ(shortestBridge(grid), res);
}