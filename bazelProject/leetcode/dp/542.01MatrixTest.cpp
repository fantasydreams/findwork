#include "542.01Matrix.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<std::vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    std::vector<std::vector<int>> ans = {{0,0,0},{0,1,0},{0,0,0}};
    EXPECT_EQ(updateMatrix(grid), ans);
}

TEST(case_2,content)
{
    std::vector<std::vector<int>> grid = {{0,0,0},{0,1,0},{1,1,1}};
    std::vector<std::vector<int>> ans = {{0,0,0},{0,1,0},{1,2,1}};
    EXPECT_EQ(updateMatrix(grid), ans);
}

TEST(case_3,content)
{
    std::vector<std::vector<int>> grid = {{1,1,0,0,1,0,0,1,1,0},{1,0,0,1,0,1,1,1,1,1},{1,1,1,0,0,1,1,1,1,0},{0,1,1,1,0,1,1,1,1,1},{0,0,1,1,1,1,1,1,1,0},{1,1,1,1,1,1,0,1,1,1},{0,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,0,0,1,1,1},{0,1,0,1,1,0,1,1,1,1},{1,1,1,0,1,0,1,1,1,1}};
    std::vector<std::vector<int>> ans = {{2,1,0,0,1,0,0,1,1,0},{1,0,0,1,0,1,1,2,2,1},{1,1,1,0,0,1,2,2,1,0},{0,1,2,1,0,1,2,3,2,1},{0,0,1,2,1,2,1,2,1,0},{1,1,2,3,2,1,0,1,1,1},{0,1,2,3,2,1,1,0,0,1},{1,2,1,2,1,0,0,1,1,2},{0,1,0,1,1,0,1,2,2,3},{1,2,1,0,1,0,1,2,3,4}};
    EXPECT_EQ(updateMatrix(grid), ans);
}