#include "54.SpiralMatrix.h"

#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    std::vector<int> ans = {1,2,3,6,9,8,7,4,5};
    EXPECT_EQ(spiralOrder(nums), ans);
    EXPECT_EQ(spiralOrder1(nums), ans);
}


TEST(case_2,content)
{
    std::vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    std::vector<int> ans = {1,2,3,4,8,12,11,10,9,5,6,7};
    EXPECT_EQ(spiralOrder(nums), ans);
    EXPECT_EQ(spiralOrder1(nums), ans);
}


TEST(case_3,content)
{
    std::vector<vector<int>> nums = {{1,2,3,4}};
    std::vector<int> ans = {1,2,3,4};
    EXPECT_EQ(spiralOrder(nums), ans);
    EXPECT_EQ(spiralOrder1(nums), ans);
}

TEST(case_4,content)
{
    std::vector<vector<int>> nums = {{1},{2},{3}};
    std::vector<int> ans = {1,2,3};
    EXPECT_EQ(spiralOrder(nums), ans);
    EXPECT_EQ(spiralOrder1(nums), ans);
}


TEST(case_5,content)
{
    std::vector<vector<int>> nums = {{1, 2},{3, 4},{5, 6}};
    std::vector<int> ans = {1,2,4,6,5,3};
    EXPECT_EQ(spiralOrder(nums), ans);
    EXPECT_EQ(spiralOrder1(nums), ans);
}