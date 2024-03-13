#include "46.Permutations.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<int> grid = {1,2,3};
    vector<vector<int>> res = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    vector<vector<int>> res1 = { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, { 2, 3, 1 }, { 3, 2, 1 }, { 3, 1, 2 } };
    EXPECT_EQ(permute(grid), res);
    EXPECT_EQ(permute1(grid), res1);
    EXPECT_EQ(permute2(grid), res1);
    EXPECT_EQ(permute3(grid), res);
    EXPECT_EQ(permute4(grid), res1);
}


TEST(case_2,content)
{
    vector<int> grid = {0, 1};
    vector<vector<int>> res = {{0, 1}, {1, 0}};
    EXPECT_EQ(permute(grid), res);
    EXPECT_EQ(permute1(grid), res);
    EXPECT_EQ(permute2(grid), res);
    EXPECT_EQ(permute3(grid), res);
    EXPECT_EQ(permute4(grid), res);
}


TEST(case_3,content)
{
    vector<int> grid = {0};
    vector<vector<int>> res = {{0}};
    EXPECT_EQ(permute(grid), res);
    EXPECT_EQ(permute1(grid), res);
    EXPECT_EQ(permute2(grid), res);
    EXPECT_EQ(permute3(grid), res);
    EXPECT_EQ(permute4(grid), res);
}

TEST(case_4,content)
{
    vector<int> grid = {5,4,6,2};
    vector<vector<int>> res = {{5,4,6,2},{5,4,2,6},{5,6,4,2},{5,6,2,4},{5,2,4,6},{5,2,6,4},{4,5,6,2},{4,5,2,6},{4,6,5,2},{4,6,2,5},{4,2,5,6},{4,2,6,5},{6,5,4,2},{6,5,2,4},{6,4,5,2},{6,4,2,5},{6,2,5,4},{6,2,4,5},{2,5,4,6},{2,5,6,4},{2,4,5,6},{2,4,6,5},{2,6,5,4},{2,6,4,5}};
    vector<vector<int>> res1 = { { 5, 4, 6, 2 }, { 5, 4, 2, 6 }, { 5, 6, 4, 2 }, { 5, 6, 2, 4 }, { 5, 2, 6, 4 }, { 5, 2, 4, 6 }, { 4, 5, 6, 2 }, { 4, 5, 2, 6 }, { 4, 6, 5, 2 }, { 4, 6, 2, 5 }, { 4, 2, 6, 5 }, { 4, 2, 5, 6 }, { 6, 4, 5, 2 }, { 6, 4, 2, 5 }, { 6, 5, 4, 2 }, { 6, 5, 2, 4 }, { 6, 2, 5, 4 }, { 6, 2, 4, 5 }, { 2, 4, 6, 5 }, { 2, 4, 5, 6 }, { 2, 6, 4, 5 }, { 2, 6, 5, 4 }, { 2, 5, 6, 4 }, { 2, 5, 4, 6 } };
    vector<vector<int>> res2 = { { 2, 4, 5, 6 }, { 2, 4, 6, 5 }, { 2, 5, 4, 6 }, { 2, 5, 6, 4 }, { 2, 6, 4, 5 }, { 2, 6, 5, 4 }, { 4, 2, 5, 6 }, { 4, 2, 6, 5 }, { 4, 5, 2, 6 }, { 4, 5, 6, 2 }, { 4, 6, 2, 5 }, { 4, 6, 5, 2 }, { 5, 2, 4, 6 }, { 5, 2, 6, 4 }, { 5, 4, 2, 6 }, { 5, 4, 6, 2 }, { 5, 6, 2, 4 }, { 5, 6, 4, 2 }, { 6, 2, 4, 5 }, { 6, 2, 5, 4 }, { 6, 4, 2, 5 }, { 6, 4, 5, 2 }, { 6, 5, 2, 4 }, { 6, 5, 4, 2 } };
    vector<vector<int>> res3 = { { 2, 4, 5, 6 }, { 2, 4, 6, 5 }, { 2, 5, 4, 6 }, { 2, 5, 6, 4 }, { 2, 6, 5, 4 }, { 2, 6, 4, 5 }, { 4, 2, 5, 6 }, { 4, 2, 6, 5 }, { 4, 5, 2, 6 }, { 4, 5, 6, 2 }, { 4, 6, 5, 2 }, { 4, 6, 2, 5 }, { 5, 4, 2, 6 }, { 5, 4, 6, 2 }, { 5, 2, 4, 6 }, { 5, 2, 6, 4 }, { 5, 6, 2, 4 }, { 5, 6, 4, 2 }, { 6, 4, 5, 2 }, { 6, 4, 2, 5 }, { 6, 5, 4, 2 }, { 6, 5, 2, 4 }, { 6, 2, 5, 4 }, { 6, 2, 4, 5 } };
    EXPECT_EQ(permute(grid), res);
    EXPECT_EQ(permute1(grid), res1);
    EXPECT_EQ(permute2(grid), res1);
    EXPECT_EQ(permute3(grid), res2);
    EXPECT_EQ(permute4(grid), res3);
}