#include "633.SumofSquareNumbers.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    EXPECT_EQ(judgeSquareSum(5), true);
    EXPECT_EQ(judgeSquareSum1(5), true);
    EXPECT_EQ(judgeSquareSum2(5), true);
}


TEST(case_2,content)
{
	EXPECT_EQ(judgeSquareSum(0), true);
    EXPECT_EQ(judgeSquareSum1(0), true);
    EXPECT_EQ(judgeSquareSum2(0), true);
}


TEST(case_3,content)
{
	EXPECT_EQ(judgeSquareSum(3), false);
    EXPECT_EQ(judgeSquareSum1(3), false);
    EXPECT_EQ(judgeSquareSum2(3), false);
}

TEST(case_4,content)
{
	EXPECT_EQ(judgeSquareSum(2147395600), true);
    EXPECT_EQ(judgeSquareSum1(2147395600), true);
    EXPECT_EQ(judgeSquareSum2(2147395600), true);
}

TEST(case_5,content)
{
	EXPECT_EQ(judgeSquareSum(2147395600), true);
    EXPECT_EQ(judgeSquareSum1(2147395600), true);
    EXPECT_EQ(judgeSquareSum2(2147395600), true);
}

TEST(case_6,content)
{
	EXPECT_EQ(judgeSquareSum(2147395600), true);
    EXPECT_EQ(judgeSquareSum1(2147395600), true);
    EXPECT_EQ(judgeSquareSum2(2147395600), true);
}

TEST(case_7,content)
{
	EXPECT_EQ(judgeSquareSum(2147483216), true);
    EXPECT_EQ(judgeSquareSum1(2147483216), true);
    EXPECT_EQ(judgeSquareSum2(2147483216), true);
}

TEST(case_8,content)
{
	EXPECT_EQ(judgeSquareSum(2147483647), false);
    // EXPECT_EQ(judgeSquareSum1(2147483647), false);
    EXPECT_EQ(judgeSquareSum2(2147483647), false);
}