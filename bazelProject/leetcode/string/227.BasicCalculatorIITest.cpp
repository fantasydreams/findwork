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
}


TEST(case_3,content)
{
	std::string str = " 3+5 / 2 ";
    int ans = 5;
    EXPECT_EQ(calculate(str), ans);
}

TEST(case_4,content)
{
	std::string str = " 31+52 / 21 ";
    int ans = 33;
    EXPECT_EQ(calculate(str), ans);
}

TEST(case_5,content)
{
	std::string str = "0";
    int ans = 0;
    EXPECT_EQ(calculate(str), ans);
}