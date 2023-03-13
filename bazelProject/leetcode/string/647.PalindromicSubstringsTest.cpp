#include "647.PalindromicSubstrings.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
	std::string s = "abc";
    int ans = 3;
    EXPECT_EQ(countSubstrings(s), ans);
}

TEST(case_2,content)
{
	std::string s = "aaa";
    int ans = 6;
    EXPECT_EQ(countSubstrings(s), ans);
}