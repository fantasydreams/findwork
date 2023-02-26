#include "172.FactorialTrailingZeroes.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    int num = 2, ans = 0;
    EXPECT_EQ(trailingZeroes(num), ans);
}

TEST(case_2,content)
{
    int num = 5, ans = 1;
    EXPECT_EQ(trailingZeroes(num), ans);
}

TEST(case_3,content)
{
    int num = 12, ans = 2;
    EXPECT_EQ(trailingZeroes(num), ans);
}

TEST(case_4,content)
{
    int num = 20, ans = 4;
    EXPECT_EQ(trailingZeroes(num), ans);
}