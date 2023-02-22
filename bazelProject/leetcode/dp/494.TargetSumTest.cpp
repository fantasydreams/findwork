#include "494.TargetSum.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {1,1,1,1,1};
    int ans = 5, target = 3;
    EXPECT_EQ(findTargetSumWays(nums, target), ans);
    EXPECT_EQ(findTargetSumWays1(nums, target), ans);
    EXPECT_EQ(findTargetSumWays3(nums, target), ans);
    EXPECT_EQ(findTargetSumWays4(nums, target), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {1000};
    int ans = 1, target = -1000;
    EXPECT_EQ(findTargetSumWays(nums, target), ans);
    EXPECT_EQ(findTargetSumWays1(nums, target), ans);
    EXPECT_EQ(findTargetSumWays3(nums, target), ans);
    EXPECT_EQ(findTargetSumWays4(nums, target), ans);
}