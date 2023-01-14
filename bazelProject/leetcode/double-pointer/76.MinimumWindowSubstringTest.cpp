#include "76.MinimumWindowSubstring.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    EXPECT_EQ(minWindow(s, t), "BANC");
}

TEST(case_2,content)
{
    std::string s = "a";
    std::string t = "a";
    EXPECT_EQ(minWindow(s, t), "a");
}

TEST(case_3,content)
{
    std::string s = "a";
    std::string t = "aa";
    EXPECT_EQ(minWindow(s, t), "");
}