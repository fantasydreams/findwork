#include "gtest/gtest.h"
#include "65.ValidNumber.h"

TEST(case_1,content)
{
	std::string s = "2";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_2,content)
{
	std::string s = "0089";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}


TEST(case_3,content)
{
	std::string s = "-0.1";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_4,content)
{
	std::string s = "+3.14";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_5,content)
{
	std::string s = "4.";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_6,content)
{
	std::string s = "-.9";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_7,content)
{
	std::string s = "2e10";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_8,content)
{
	std::string s = "-90E3";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_9,content)
{
	std::string s = "3e+7";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_10,content)
{
	std::string s = "+6e-1";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_11,content)
{
	std::string s = "53.5e93";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_12,content)
{
	std::string s = "-123.456e789";
    bool ans = true;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_13,content)
{
	std::string s = "abc";
    bool ans = false;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_14,content)
{
	std::string s = "1a";
    bool ans = false;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_15,content)
{
	std::string s = "1e";
    bool ans = false;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_20,content)
{
	std::string s = "e3";
    bool ans = false;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_16,content)
{
	std::string s = "99e2.5";
    bool ans = false;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_17,content)
{
	std::string s = "--6";
    bool ans = false;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_18,content)
{
	std::string s = "-+3";
    bool ans = false;
    EXPECT_EQ(isNumber(s), ans);
}

TEST(case_19,content)
{
	std::string s = "95a54e53";
    bool ans = false;
    EXPECT_EQ(isNumber(s), ans);
}
