#include "202.HappyNumber.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    int n = 1;
    bool ans = true;
    EXPECT_EQ(isHappy(n), ans);
    EXPECT_EQ(isHappyMap(n), ans);
    EXPECT_EQ(isHappyHash(n), ans);
}

TEST(case_2,content)
{
    int n = 19;
    bool ans = true;
    EXPECT_EQ(isHappy(n), ans);
    EXPECT_EQ(isHappyMap(n), ans);
    EXPECT_EQ(isHappyHash(n), ans);
}

TEST(case_3,content)
{
    int n = 2;
    bool ans = false;
    EXPECT_EQ(isHappy(n), ans);
    EXPECT_EQ(isHappyMap(n), ans);
    EXPECT_EQ(isHappyHash(n), ans);
}