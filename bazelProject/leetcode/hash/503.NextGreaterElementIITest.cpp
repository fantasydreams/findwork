#include "503.NextGreaterElementII.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    std::vector<int> nums = {1,2,1};
    std::vector<int> ans = {2,-1,2};
    EXPECT_EQ(nextGreaterElements(nums), ans);   
}


TEST(case_2,content)
{
    std::vector<int> nums = {1,2,3,4,3};
    std::vector<int> ans = {2,3,4,-1,4};
    EXPECT_EQ(nextGreaterElements(nums), ans);   
}