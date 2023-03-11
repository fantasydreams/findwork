#include "217.ContainsDuplicate.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    vector<int> nums = {1,2,3,1};
    bool ans = true;
    EXPECT_EQ(containsDuplicate(nums), ans);
}


TEST(case_2,content)
{
    vector<int> nums = {1,2,3,4};
    bool ans = false;
    EXPECT_EQ(containsDuplicate(nums), ans);
}

TEST(case_3,content)
{
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    bool ans = true;
    EXPECT_EQ(containsDuplicate(nums), ans);
}