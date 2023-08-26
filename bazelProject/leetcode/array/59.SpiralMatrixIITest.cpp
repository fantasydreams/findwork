#include "59.SpiralMatrixII.h"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>

TEST(case_1, content)
{
    vector<vector<int>> ans = {{1}};
    int n = 1;
    EXPECT_EQ(generateMatrix(n), ans);
}


TEST(case_2, content)
{
    vector<vector<int>> ans = {};
    int n = 0;
    EXPECT_EQ(generateMatrix(n), ans);
}

TEST(case_3, content)
{
    vector<vector<int>> ans = {{1,2},{4,3}};
    int n = 2;
    EXPECT_EQ(generateMatrix(n), ans);
}

TEST(case_4, content)
{
    vector<vector<int>> ans = {{1,2,3},{8,9,4},{7,6,5}};
    int n = 3;
    EXPECT_EQ(generateMatrix(n), ans);
}