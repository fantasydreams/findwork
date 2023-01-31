#include "300.LongestIncreasingSubsequence.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {10,9,2,5,3,7,101,18};
    int ans = 4;
    EXPECT_EQ(lengthOfLIS(nums), ans);
    EXPECT_EQ(lengthOfLIS1(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {0,1,0,3,2,3};
    int ans = 4;
    EXPECT_EQ(lengthOfLIS(nums), ans);
    EXPECT_EQ(lengthOfLIS1(nums), ans);
}


TEST(case_3,content)
{
    std::vector<int> nums = {7,7,7,7,7,7,7,7};
    int ans = 1;
    EXPECT_EQ(lengthOfLIS(nums), ans);
    EXPECT_EQ(lengthOfLIS1(nums), ans);
}