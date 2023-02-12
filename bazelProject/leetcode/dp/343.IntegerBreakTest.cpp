#include "343.IntegerBreak.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1, content)
{
    int n = 2, res = 1;
    EXPECT_EQ(integerBreak(n), res);
    EXPECT_EQ(integerBreak1(n), res);
    EXPECT_EQ(integerBreak2(n), res);
    EXPECT_EQ(integerBreak3(n), res);
}

TEST(case_2, content)
{
    int n = 3, res = 2;
    EXPECT_EQ(integerBreak(n), res);
    EXPECT_EQ(integerBreak1(n), res);
    EXPECT_EQ(integerBreak2(n), res);
    EXPECT_EQ(integerBreak3(n), res);
}

TEST(case_3, content)
{
    int n = 10, res = 36;
    EXPECT_EQ(integerBreak(n), res);
    EXPECT_EQ(integerBreak1(n), res);
    EXPECT_EQ(integerBreak2(n), res);
    EXPECT_EQ(integerBreak3(n), res);
}