#include "494.TargetSum.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {1,1,1,1,1};
    int ans = 5, target = 3;
    EXPECT_EQ(findTargetSumWays(nums, target), ans);
    EXPECT_EQ(findTargetSumWays2(nums, target), ans);
}