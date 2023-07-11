#include "gtest/gtest.h"
#include "bytedance.balljump.h"

TEST(case_1,content)
{
    int height = 10;
    int n = 1;
    double ans = height;
    EXPECT_EQ(nJumpLen(height, n), ans);
}

TEST(case_2,content)
{
    int height = 10;
    int n = 2;
    double ans = 20;
    EXPECT_EQ(nJumpLen(height, n), ans);
}