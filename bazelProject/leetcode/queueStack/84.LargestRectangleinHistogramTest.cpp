#include "gtest/gtest.h"
#include "84.LargestRectangleinHistogram.h"

TEST(case_1,content)
{
    std::vector<int> vec = {2,1,5,6,2,3};
    int ans = 10;
    EXPECT_EQ(largestRectangleArea(vec), ans);
}

TEST(case_2,content)
{
    std::vector<int> vec = {2,4};
    int ans = 4;
    EXPECT_EQ(largestRectangleArea(vec), ans);
}

TEST(case_3,content)
{
    std::vector<int> vec = {};
    int ans = 0;
    EXPECT_EQ(largestRectangleArea(vec), ans);
}


TEST(case_4,content)
{
    std::vector<int> vec = {1};
    int ans = 1;
    EXPECT_EQ(largestRectangleArea(vec), ans);
}

