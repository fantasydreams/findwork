#include "67.AddBinary.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    string a = "101", b = "1";
    string ans = "110";
    EXPECT_EQ(addBinary(a, b), ans);
    EXPECT_EQ(addBinary1(a, b), ans);
}

TEST(case_2,content)
{
    string a = "1010", b = "1011";
    string ans = "10101";
    EXPECT_EQ(addBinary(a, b), ans);
    EXPECT_EQ(addBinary1(a, b), ans);
}