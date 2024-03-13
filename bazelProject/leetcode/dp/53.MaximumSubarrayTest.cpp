#include "53.MaximumSubarray.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = 6;
    EXPECT_EQ(maxSubArray(nums), ans);
    EXPECT_EQ(maxSubArray1(nums), ans);
    EXPECT_EQ(maxSubArray1(nums), ans);
    EXPECT_EQ(maxSubArray3(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {1};
    int ans = 1;
    EXPECT_EQ(maxSubArray(nums), ans);
    EXPECT_EQ(maxSubArray1(nums), ans);
    EXPECT_EQ(maxSubArray2(nums), ans);
    EXPECT_EQ(maxSubArray3(nums), ans);
}

TEST(case_3,content)
{
    std::vector<int> nums = {5,4,-1,7,8};
    int ans = 23;
    EXPECT_EQ(maxSubArray(nums), ans);
    EXPECT_EQ(maxSubArray1(nums), ans);
    EXPECT_EQ(maxSubArray2(nums), ans);
    EXPECT_EQ(maxSubArray3(nums), ans);
}

TEST(case_4,content)
{
    std::vector<int> nums = {0};
    int ans = 0;
    EXPECT_EQ(maxSubArray(nums), ans);
    EXPECT_EQ(maxSubArray1(nums), ans);
    EXPECT_EQ(maxSubArray2(nums), ans);
    EXPECT_EQ(maxSubArray3(nums), ans);
}