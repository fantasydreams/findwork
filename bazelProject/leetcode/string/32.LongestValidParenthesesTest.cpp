#include "gtest/gtest.h"
#include <vector>
#include "32.LongestValidParentheses.h"

TEST(case_1, content)
{
    int ans = 2;
    std::string str = "()";
    EXPECT_EQ(longestValidParentheses(str), ans);
    EXPECT_EQ(longestValidParentheses1(str), ans);
    EXPECT_EQ(longestValidParenthesesDp(str), ans);
}

TEST(case_2, content)
{
    int ans = 2;
    std::string str = "())";
    EXPECT_EQ(longestValidParentheses(str), ans);
    EXPECT_EQ(longestValidParentheses1(str), ans);
    EXPECT_EQ(longestValidParenthesesDp(str), ans);
}

TEST(case_3, content)
{
    int ans = 0;
    std::string str = "))";
    EXPECT_EQ(longestValidParentheses(str), ans);
    EXPECT_EQ(longestValidParentheses1(str), ans);
    EXPECT_EQ(longestValidParenthesesDp(str), ans);
}


TEST(case_4, content)
{
    int ans = 16;
    std::string str = "()()(())()((()))";
    EXPECT_EQ(longestValidParentheses(str), ans);
    EXPECT_EQ(longestValidParentheses1(str), ans);
    EXPECT_EQ(longestValidParenthesesDp(str), ans);
}


TEST(case_5, content)
{
    int ans = 16;
    std::string str = "()()(())()((())))(";
    EXPECT_EQ(longestValidParentheses(str), ans);
    EXPECT_EQ(longestValidParentheses1(str), ans);
    EXPECT_EQ(longestValidParenthesesDp(str), ans);
}


TEST(case_6, content)
{
    int ans = 2;
    std::string str = "(()";
    EXPECT_EQ(longestValidParentheses(str), ans);
    EXPECT_EQ(longestValidParentheses1(str), ans);
    EXPECT_EQ(longestValidParenthesesDp(str), ans);
}