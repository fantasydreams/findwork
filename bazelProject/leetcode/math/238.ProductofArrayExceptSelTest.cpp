#include "238.ProductofArrayExceptSel.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    vector<int> nums = {1,2,3};
    vector<int> ans = {6,3,2};
    EXPECT_EQ(productExceptSelf(nums), ans);
    EXPECT_EQ(productExceptSelf1(nums), ans);
}

TEST(case_2,content)
{
    vector<int> nums = {1,2,3,4};
    vector<int> ans = {24,12,8,6};
    EXPECT_EQ(productExceptSelf(nums), ans);
    EXPECT_EQ(productExceptSelf(nums), ans);
}

TEST(case_3,content)
{
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> ans = {0,0,9,0,0};
    EXPECT_EQ(productExceptSelf(nums), ans);
    EXPECT_EQ(productExceptSelf(nums), ans);
}

TEST(case_4,content)
{
    vector<int> nums = {-1,0,0,-3,3};
    vector<int> ans = {0,0,0,0,0};
    EXPECT_EQ(productExceptSelf(nums), ans);
    EXPECT_EQ(productExceptSelf(nums), ans);
}