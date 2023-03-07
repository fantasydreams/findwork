#include "260.SingleNumberIII.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> ans = {3,5};
    vector<int> tmp = singleNumber(nums);
    sort(tmp.begin(), tmp.end());
    EXPECT_EQ(tmp, ans);
}

TEST(case_2,content)
{
    vector<int> nums = {1, 0};
    vector<int> ans = {0,1};
    vector<int> tmp = singleNumber(nums);
    sort(tmp.begin(), tmp.end());
    EXPECT_EQ(tmp, ans);
}

TEST(case_3,content)
{
    vector<int> nums = {-1, 0};
    vector<int> ans = {-1,0};
    vector<int> tmp = singleNumber(nums);
    sort(tmp.begin(), tmp.end());
    EXPECT_EQ(tmp, ans);
}