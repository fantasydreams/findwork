#include "415.AddStrings.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    string s1 = "11", s2 = "123", ans = "134";
    EXPECT_EQ(addStrings(s1, s2), ans);
}

TEST(case_2,content)
{
    string s1 = "0", s2 = "0", ans = "0";
    EXPECT_EQ(addStrings(s1, s2), ans);
    EXPECT_EQ(addStrings1(s1, s2), ans);
}

TEST(case_3,content)
{
    string s1 = "456", s2 = "77", ans = "533";
    EXPECT_EQ(addStrings(s1, s2), ans);
    EXPECT_EQ(addStrings1(s1, s2), ans);
}

TEST(case_4,content)
{
    string s1 = "99", s2 = "1", ans = "100";
    EXPECT_EQ(addStrings(s1, s2), ans);
    EXPECT_EQ(addStrings1(s1, s2), ans);
}