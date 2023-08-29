#include "67.AddBinary.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::string s1 = "1", s2 = "0";
    std::string ans = "1";
    EXPECT_EQ(addBinary(s1, s2), ans);
}

TEST(case_2, content)
{
    std::string s1 = "0", s2 = "0";
    std::string ans = "0";
    EXPECT_EQ(addBinary(s1, s2), ans);
}

TEST(case_3, content)
{
    std::string s1 = "1", s2;
    std::string ans = "1";
    EXPECT_EQ(addBinary(s1, s2), ans);
}

TEST(case_4, content)
{
    std::string s1, s2;
    std::string ans = "0";
    EXPECT_EQ(addBinary(s1, s2), ans);
}


TEST(case_5, content)
{
    std::string s1 = "1", s2;
    std::string ans = "1";
    EXPECT_EQ(addBinary(s1, s2), ans);
}

TEST(case_6, content)
{
    std::string s1 = "00", s2;
    std::string ans = "0";
    EXPECT_EQ(addBinary(s1, s2), ans);
}


TEST(case_7, content)
{
    std::string s1 = "0011", s2 = "1";
    std::string ans = "100";
    EXPECT_EQ(addBinary(s1, s2), ans);
}

TEST(case_8, content)
{
    std::string s1 = "1010", s2 = "1011";
    std::string ans = "10101";
    EXPECT_EQ(addBinary(s1, s2), ans);
}