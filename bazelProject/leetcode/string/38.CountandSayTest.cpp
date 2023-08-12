#include "38.CountandSay.h"
#include "gtest/gtest.h"
#include <vector>

TEST(case_1, content)
{
    int n = 0;
    std::string ans = "";

    EXPECT_EQ(countAndSay(n), ans);
}


TEST(case_9, content)
{
    int n = 1;
    std::string ans = "1";

    EXPECT_EQ(countAndSay(n), ans);
    EXPECT_EQ(countAndSay1(n), ans);
}


TEST(case_2, content)
{
    int n = 2;
    std::string ans = "11";

    EXPECT_EQ(countAndSay(n), ans);
    EXPECT_EQ(countAndSay1(n), ans);
}


TEST(case_3, content)
{
    int n = 3;
    std::string ans = "21";

    EXPECT_EQ(countAndSay(n), ans);
    EXPECT_EQ(countAndSay1(n), ans);
}

TEST(case_4, content)
{
    int n = 4;;
    std::string ans = "1211";

    EXPECT_EQ(countAndSay(n), ans);
    EXPECT_EQ(countAndSay1(n), ans);
}

TEST(case_5, content)
{
    int n = 5;
    std::string ans = "111221";

    EXPECT_EQ(countAndSay(n), ans);
    EXPECT_EQ(countAndSay1(n), ans);
}

TEST(case_6, content)
{
    int n = 6;
    std::string ans = "312211";

    EXPECT_EQ(countAndSay(n), ans);
    EXPECT_EQ(countAndSay1(n), ans);
}

TEST(case_7, content)
{
    int n = 7;
    std::string ans = "13112221";

    EXPECT_EQ(countAndSay(n), ans);
    EXPECT_EQ(countAndSay1(n), ans);
}

TEST(case_8, content)
{
    int n = 8;
    std::string ans = "1113213211";

    EXPECT_EQ(countAndSay(n), ans);
    EXPECT_EQ(countAndSay1(n), ans);
}