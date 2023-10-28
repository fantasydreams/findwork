#include "164.MaximumGap.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int ans = 3;
    std::vector<int> nums = {3,6,9,1};
    EXPECT_EQ(maximumGap(nums), ans);
}


TEST(case_2, content) {
    int ans = 0;
    std::vector<int> nums = {10};
    EXPECT_EQ(maximumGap(nums), ans);
}

TEST(case_3, content) {
    int ans = 97;
    std::vector<int> nums = {100,3,2,1};
    EXPECT_EQ(maximumGap(nums), ans);
}