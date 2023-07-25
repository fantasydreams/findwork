#include "20.ValidParentheses.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::string str = "()";
    bool ans = true;
    EXPECT_EQ(isValid(str), ans);
    EXPECT_EQ(isValid1(str), ans);
}

TEST(case_2,content)
{
    std::string str = "()[]{}";
    bool ans = true;
    EXPECT_EQ(isValid(str), ans);
    EXPECT_EQ(isValid1(str), ans);
}

TEST(case_3,content)
{
    std::string str = "(]";
    bool ans = false;
    EXPECT_EQ(isValid(str), ans);
    EXPECT_EQ(isValid1(str), ans);
}

TEST(case_4,content)
{
    std::string str = "(";
    bool ans = false;
    EXPECT_EQ(isValid(str), ans);
    EXPECT_EQ(isValid1(str), ans);
}