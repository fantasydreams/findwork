#include "213.HouseRobberII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {2,3,2};
    int ans = 3;
    EXPECT_EQ(rob(nums), ans);
    EXPECT_EQ(rob1(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {1,2,3,1};
    int ans = 4;
    EXPECT_EQ(rob(nums), ans);
    EXPECT_EQ(rob1(nums), ans);
}

TEST(case_3,content)
{
    std::vector<int> nums = {1,2,3};
    int ans = 3;
    EXPECT_EQ(rob(nums), ans);
    EXPECT_EQ(rob1(nums), ans);
}

TEST(case_4,content)
{
    std::vector<int> nums = {3,2,1,5};
    int ans = 7;
    EXPECT_EQ(rob(nums), ans);
    EXPECT_EQ(rob1(nums), ans);
}

TEST(case_5,content)
{
    std::vector<int> nums = {3,2,1,5,1};
    int ans = 8;
    EXPECT_EQ(rob(nums), ans);
    EXPECT_EQ(rob1(nums), ans);
}