#include "1143.LongestCommonSubsequence.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string text1 = "abcde";
    std::string text2 = "ace";
    int ans = 3;
    EXPECT_EQ(longestCommonSubsequence(text1, text2), ans);
}

TEST(case_2,content)
{
    std::string text1 = "abc";
    std::string text2 = "abc";
    int ans = 3;
    EXPECT_EQ(longestCommonSubsequence(text1, text2), ans);
}

TEST(case_3,content)
{
    std::string text1 = "abc";
    std::string text2 = "def";
    int ans = 0;
    EXPECT_EQ(longestCommonSubsequence(text1, text2), ans);
}