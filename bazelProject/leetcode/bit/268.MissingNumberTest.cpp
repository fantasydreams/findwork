#include "268.MissingNumber.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    vector<int> nums = {3,0,1};
    int ans = 2;
    EXPECT_EQ(missingNumber(nums), ans);
    EXPECT_EQ(missingNumber1(nums), ans);
}

TEST(case_2,content)
{
    vector<int> nums = {0,1};
    int ans = 2;
    EXPECT_EQ(missingNumber(nums), ans);
    EXPECT_EQ(missingNumber1(nums), ans);
}