#include "76.MinimumWindowSubstring.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::string s = "ADOBECODEBANC", t = "ABC";
    std::string ans = "BANC";
    EXPECT_EQ(minWindow(s, t), ans);
}


TEST(case_2, content)
{
    std::string s = "a", t = "a";
    std::string ans = "a";
    EXPECT_EQ(minWindow(s, t), ans);
}

TEST(case_3, content)
{
    std::string s = "a", t = "aa";
    std::string ans = "";
    EXPECT_EQ(minWindow(s, t), ans);
}