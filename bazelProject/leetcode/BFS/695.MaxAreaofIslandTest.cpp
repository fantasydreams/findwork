#include "695.MaxAreaofIsland.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    EXPECT_EQ(maxAreaOfIsland(grid), 6);
    EXPECT_EQ(maxAreaOfIsland1(grid), 6);
    grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    EXPECT_EQ(maxAreaOfIsland2(grid), 6);
}


TEST(case_2,content)
{
    vector<vector<int>> grid = {{0,0,0,0,0,0,0,0}};
    EXPECT_EQ(maxAreaOfIsland(grid), 0);
    EXPECT_EQ(maxAreaOfIsland1(grid), 0);
    grid = {{0,0,0,0,0,0,0,0}};
    EXPECT_EQ(maxAreaOfIsland2(grid), 0);
}


TEST(case_3,content)
{
    vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    EXPECT_EQ(maxAreaOfIsland(grid), 4);
    EXPECT_EQ(maxAreaOfIsland1(grid), 4);
    grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    EXPECT_EQ(maxAreaOfIsland2(grid), 4);
}
