#include "gtest/gtest.h"
#include <climits>
#include "29.DivideTwoIntegers.h"


TEST(case_1,content)
{
	int dividend = INT_MAX, divisor = -1;
    int ans = INT_MIN + 1;
    EXPECT_EQ(divide(dividend, divisor), ans);
}


TEST(case_2,content)
{
	int dividend = INT_MIN, divisor = -1;
    int ans = INT_MAX;
    EXPECT_EQ(divide(dividend, divisor), ans);
}


TEST(case_3,content)
{
	int dividend = 10, divisor = 2;
    int ans = 5;
    EXPECT_EQ(divide(dividend, divisor), ans);
}


TEST(case_4,content)
{
	int dividend = 10, divisor = -2;
    int ans = -5;
    EXPECT_EQ(divide(dividend, divisor), ans);
}

TEST(case_5,content)
{
	int dividend = 10, divisor = 3;
    int ans = 3;
    EXPECT_EQ(divide(dividend, divisor), ans);
}

TEST(case_6,content)
{
	int dividend = 7, divisor = -3;
    int ans = -2;
    EXPECT_EQ(divide(dividend, divisor), ans);
}


TEST(case_7, content)
{
	int dividend = -2147483648, divisor = 2;
    int ans = -1073741824;
    EXPECT_EQ(divide(dividend, divisor), ans);
}
