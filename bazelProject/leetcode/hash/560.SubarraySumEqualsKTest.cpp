#include "560.SubarraySumEqualsK.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> nums = {1,1,1};
    int k = 2;
    int ans = 2;
    EXPECT_EQ(subarraySum(nums, k), ans);   
    EXPECT_EQ(subarraySum1(nums, k), ans);   
}

TEST(case_2,content)
{
    std::vector<int> nums = {1,2,3};
    int k = 3;
    int ans = 2;
    EXPECT_EQ(subarraySum(nums, k), ans);   
    EXPECT_EQ(subarraySum1(nums, k), ans);   
}

TEST(case_3,content)
{
    std::vector<int> nums = {1,0,0,1,-1};
    int k = 0;
    int ans = 6;
    EXPECT_EQ(subarraySum(nums, k), ans);   
    EXPECT_EQ(subarraySum1(nums, k), ans);   
}