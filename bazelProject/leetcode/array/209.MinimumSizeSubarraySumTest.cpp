#include "209.MinimumSizeSubarraySum.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int target = 7;
    int ans = 2;
    std::vector<int> nums = {2,3,1,2,4,3};
    EXPECT_EQ(minSubArrayLen(target, nums), ans);
}

TEST(case_2, content) {
    int target = 4;
    int ans = 1;
    std::vector<int> nums = {1,4,4};
    EXPECT_EQ(minSubArrayLen(target, nums), ans);
}

TEST(case_3, content) {
    int target = 11;
    int ans = 0;
    std::vector<int> nums = {1,1,1,1,1,1,1,1};
    EXPECT_EQ(minSubArrayLen(target, nums), ans);
}

TEST(case_4, content) {
    int target = 15;
    int ans = 2;
    std::vector<int> nums = {5,1,3,5,10,7,4,9,2,8};
    EXPECT_EQ(minSubArrayLen(target, nums), ans);
}