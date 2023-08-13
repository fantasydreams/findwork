
#include "43.MultiplyStrings.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::string a = "000", b = "123";
    std::string ans = "0";
    EXPECT_EQ(multiply(a, b), ans);
}


TEST(case_2,content)
{
    std::string a = "001", b = "123";
    std::string ans = "123";
    EXPECT_EQ(multiply(a, b), ans);
}


TEST(case_3,content)
{
    std::string a = "2", b = "3";
    std::string ans = "6";
    EXPECT_EQ(multiply(a, b), ans);
}

TEST(case_4,content)
{
    std::string a = "123", b = "456";
    std::string ans = "56088";
    EXPECT_EQ(multiply(a, b), ans);
}


TEST(case_5,content)
{
    std::string a = "9133", b = "0";
    std::string ans = "0";
    EXPECT_EQ(multiply(a, b), ans);
}