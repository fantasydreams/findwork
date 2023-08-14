#include "44.WildcardMatching.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    bool ans = false;
    std::string s = "aa", p = "a";
    EXPECT_EQ(isMatch(s, p), ans);
}

TEST(case_2,content)
{
    bool ans = true;
    std::string s = "aa", p = "*";
    EXPECT_EQ(isMatch(s, p), ans);
}


TEST(case_3,content)
{
    bool ans = false;
    std::string s = "cb", p = "?a";
    EXPECT_EQ(isMatch(s, p), ans);
}

TEST(case_4,content)
{
    bool ans = true;
    std::string s = "abc", p = "a**";
    EXPECT_EQ(isMatch(s, p), ans);
}


TEST(case_5,content)
{
    bool ans = false;
    std::string s = "", p = "?";
    EXPECT_EQ(isMatch(s, p), ans);
}


TEST(case_6,content)
{
    bool ans = true;
    std::string s = "9bbddd", p = "?b*d*";
    EXPECT_EQ(isMatch(s, p), ans);
}