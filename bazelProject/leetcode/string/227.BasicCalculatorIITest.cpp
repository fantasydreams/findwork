#include "227.BasicCalculatorII.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
	std::string str = "3+5/2";
    int ans = 5;
    EXPECT_EQ(calculate(str), ans);
}


TEST(case_2,content)
{
	std::string str = " 3/2 ";
    int ans = 1;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}


TEST(case_3,content)
{
	std::string str = " 3+5 / 2 ";
    int ans = 5;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}

TEST(case_4,content)
{
	std::string str = " 31+52 / 21 ";
    int ans = 33;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}

TEST(case_5,content)
{
	std::string str = "0";
    int ans = 0;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}

TEST(case_6,content)
{
	std::string str = "-123";
    int ans = -123;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}

TEST(case_7,content)
{
	std::string str = "-123 + 4 / 5";
    int ans = -123;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}

TEST(case_8,content)
{
	std::string str = "-123 + 4 * 5";
    int ans = -103;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}


TEST(case_9,content)
{
	std::string str = "2*5-9";
    int ans = 1;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}

TEST(case_10,content)
{
	std::string str = "100/2-1+5*3";
    int ans = 64;
    EXPECT_EQ(calculate(str), ans);
    EXPECT_EQ(calculate1(str), ans);
}