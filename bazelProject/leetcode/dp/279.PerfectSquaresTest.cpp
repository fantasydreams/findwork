#include "279.PerfectSquares.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int n = 0;
    int ans = 0;
    EXPECT_EQ(numSquares(n), ans);
    EXPECT_EQ(numSquares1(n), ans);
}

TEST(case_2,content)
{
    int n = 1;
    int ans = 1;
    EXPECT_EQ(numSquares(n), ans);
    EXPECT_EQ(numSquares1(n), ans);
}

TEST(case_3,content)
{
    int n = 2;
    int ans = 2;
    EXPECT_EQ(numSquares(n), ans);
    EXPECT_EQ(numSquares1(n), ans);
}

TEST(case_7,content)
{
    int n = 3;
    int ans = 3;
    EXPECT_EQ(numSquares(n), ans);
    EXPECT_EQ(numSquares1(n), ans);
}

TEST(case_4,content)
{
    int n = 4;
    int ans = 1;
    EXPECT_EQ(numSquares(n), ans);
    EXPECT_EQ(numSquares1(n), ans);
}

TEST(case_5,content)
{
    int n = 12;
    int ans = 3;
    EXPECT_EQ(numSquares(n), ans);
    EXPECT_EQ(numSquares1(n), ans);
}

TEST(case_6,content)
{
    int n = 13;
    int ans = 2;
    EXPECT_EQ(numSquares(n), ans);
    EXPECT_EQ(numSquares1(n), ans);
}