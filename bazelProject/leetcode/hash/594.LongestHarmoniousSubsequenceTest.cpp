#include "594.LongestHarmoniousSubsequence.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> nums = {1,3,2,2,5,2,3,7};
    int ans = 5;
    EXPECT_EQ(findLHS(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {1,2,3,4};
    int ans = 2;
    EXPECT_EQ(findLHS(nums), ans);
}

TEST(case_3,content)
{
    std::vector<int> nums = {1,1,1,1};
    int ans = 0;
    EXPECT_EQ(findLHS(nums), ans);
}

TEST(case_4,content)
{
    std::vector<int> nums = {1,2,1,3,0,0,2,2,1,3,3};
    int ans = 6;
    EXPECT_EQ(findLHS(nums), ans);
}
