#include "87.ScrambleString.h"

#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string s1 = "great", s2 = "rgeat";
    bool ans = true;
    EXPECT_EQ(isScramble(s1, s2), ans);
    EXPECT_EQ(isScramble(s1, s2), ans);
}

TEST(case_2,content)
{
    std::string s1 = "abcde", s2 = "caebd";
    bool ans = false;
    EXPECT_EQ(isScramble(s1, s2), ans);
    EXPECT_EQ(isScramble(s1, s2), ans);
}

TEST(case_3,content)
{
    std::string s1 = "a", s2 = "a";
    bool ans = true;
    EXPECT_EQ(isScramble(s1, s2), ans);
    EXPECT_EQ(isScramble(s1, s2), ans);
}