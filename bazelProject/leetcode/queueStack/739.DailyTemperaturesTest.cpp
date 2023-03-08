#include "739.DailyTemperatures.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    vector<int> nums = {73,74,75,71,69,72,76,73};
    vector<int> ans = {1,1,4,2,1,1,0,0};
    EXPECT_EQ(dailyTemperatures(nums), ans);
    EXPECT_EQ(dailyTemperatures1(nums), ans);
}

TEST(case_2,content)
{
    vector<int> nums = {30,40,50,60};
    vector<int> ans = {1,1,1,0};
    EXPECT_EQ(dailyTemperatures(nums), ans);
    EXPECT_EQ(dailyTemperatures1(nums), ans);
}

TEST(case_3,content)
{
    vector<int> nums = {30,60,90};
    vector<int> ans = {1,1,0};
    EXPECT_EQ(dailyTemperatures(nums), ans);
    EXPECT_EQ(dailyTemperatures1(nums), ans);
}