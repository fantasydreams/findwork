#include "239.SlidingWindowMaximum.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = {3,3,5,5,6,7};
    int k = 3;
    EXPECT_EQ(maxSlidingWindow(nums, k), ans);
    EXPECT_EQ(maxSlidingWindow1(nums, k), ans);
    EXPECT_EQ(maxSlidingWindow2(nums, k), ans);
}

TEST(case_2,content)
{
    vector<int> nums = {1};
    vector<int> ans = {1};
    int k = 1;
    EXPECT_EQ(maxSlidingWindow(nums, k), ans);
    EXPECT_EQ(maxSlidingWindow1(nums, k), ans);
    EXPECT_EQ(maxSlidingWindow2(nums, k), ans);
}