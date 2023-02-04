#include "650.2KeysKeyboard.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int n = 3, ans = 3;
    EXPECT_EQ(minSteps(n), ans);
    EXPECT_EQ(minSteps1(n), ans);
    EXPECT_EQ(minSteps2(n), ans);
}

TEST(case_2,content)
{
    int n = 1, ans = 0;
    EXPECT_EQ(minSteps(n), ans);
    EXPECT_EQ(minSteps1(n), ans);
    EXPECT_EQ(minSteps2(n), ans);
}


TEST(case_3,content)
{
    int n = 2, ans = 2;
    EXPECT_EQ(minSteps(n), ans);
    EXPECT_EQ(minSteps1(n), ans);
    EXPECT_EQ(minSteps2(n), ans);
}

TEST(case_4,content)
{
    int n = 5, ans = 5;
    EXPECT_EQ(minSteps(n), ans);
    EXPECT_EQ(minSteps1(n), ans);
    EXPECT_EQ(minSteps2(n), ans);
}

TEST(case_5,content)
{
    int n = 6, ans = 5;
    EXPECT_EQ(minSteps(n), ans);
    EXPECT_EQ(minSteps1(n), ans);
    EXPECT_EQ(minSteps2(n), ans);
}

TEST(case_6,content)
{
    int n = 30, ans = 10;
    EXPECT_EQ(minSteps(n), ans);
    EXPECT_EQ(minSteps1(n), ans);
    EXPECT_EQ(minSteps2(n), ans);
}

TEST(case_9,content)
{
    int n = 9, ans = 6;
    EXPECT_EQ(minSteps(n), ans);
    EXPECT_EQ(minSteps1(n), ans);
    EXPECT_EQ(minSteps2(n), ans);
}