#include "70.ClimbingStairs.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int n = 1;
    int ans = 1;
    EXPECT_EQ(climbStairs(n), ans);
    EXPECT_EQ(climbStairsDp(n), ans);
    EXPECT_EQ(climbStairs1(n), ans);
}

TEST(case_2,content)
{
    int n = 2;
    int ans = 2;
    EXPECT_EQ(climbStairs(n), ans);
    EXPECT_EQ(climbStairsDp(n), ans);
    EXPECT_EQ(climbStairs1(n), ans);
}

TEST(case_3,content)
{
    int n = 3;
    int ans = 3;
    EXPECT_EQ(climbStairs(n), ans);
    EXPECT_EQ(climbStairsDp(n), ans);
    EXPECT_EQ(climbStairs1(n), ans);
}

TEST(case_4,content)
{
    int n = 4;
    int ans = 5;
    EXPECT_EQ(climbStairs(n), ans);
    EXPECT_EQ(climbStairsDp(n), ans);
    EXPECT_EQ(climbStairs1(n), ans);
}