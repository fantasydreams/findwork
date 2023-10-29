#include "169.MajorityElement.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    vector<int> nums = {3,2,3};
    int ans = 3;
    EXPECT_EQ(majorityElement(nums), ans);
    EXPECT_EQ(majorityElement1(nums), ans);
}

TEST(case_2,content)
{
    vector<int> nums = {2,2,1,1,1,2,2};
    int ans = 2;
    EXPECT_EQ(majorityElement(nums), ans);
    EXPECT_EQ(majorityElement1(nums), ans);
}