#include "504.Base7.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    int n = 0;
    std::string ans = "0";
    EXPECT_EQ(convertToBase7(n), ans);
}

TEST(case_2, content)
{
    int n = -1;
    std::string ans = "-1";
    EXPECT_EQ(convertToBase7(n), ans);
}

TEST(case_3, content)
{
    int n = -1;
    std::string ans = "-1";
    EXPECT_EQ(convertToBase7(n), ans);
}

TEST(case_4, content)
{
    int n = 100;
    std::string ans = "202";
    EXPECT_EQ(convertToBase7(n), ans);
}

TEST(case_5, content)
{
    int n = -7;
    std::string ans = "-10";
    EXPECT_EQ(convertToBase7(n), ans);
}