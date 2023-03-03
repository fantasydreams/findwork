#include "136.SingleNumber.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    std::vector<int> nums = {1,1,2};
    int ans = 2;
    EXPECT_EQ(singleNumber(nums), ans);
}


TEST(case_2,content)
{
    std::vector<int> nums = {1,2,2};
    int ans = 1;
    EXPECT_EQ(singleNumber(nums), ans);
}


TEST(case_3,content)
{
    std::vector<int> nums = {4,1,2,1,2};
    int ans = 4;
    EXPECT_EQ(singleNumber(nums), ans);
}

TEST(case_4,content)
{
    std::vector<int> nums = {1};
    int ans = 1;
    EXPECT_EQ(singleNumber(nums), ans);
}