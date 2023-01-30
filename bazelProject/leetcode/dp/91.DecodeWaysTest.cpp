#include "91.DecodeWays.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string str = "12";
    int ans = 2;
    EXPECT_EQ(numDecodings(str), ans);
}

TEST(case_2,content)
{
    std::string str = "226";
    int ans = 3;
    EXPECT_EQ(numDecodings(str), ans);
}

TEST(case_3,content)
{
    std::string str = "06";
    int ans = 0;
    EXPECT_EQ(numDecodings(str), ans);
}

TEST(case_4,content)
{
    std::string str = "601";
    int ans = 0;
    EXPECT_EQ(numDecodings(str), ans);
}

TEST(case_5,content)
{
    std::string str = "1012";
    int ans = 2;
    EXPECT_EQ(numDecodings(str), ans);
}


TEST(case_6,content)
{
    std::string str = "1201234";
    int ans = 3;
    EXPECT_EQ(numDecodings(str), ans);
}

TEST(case_7,content)
{
    std::string str = "120";
    int ans = 1;
    EXPECT_EQ(numDecodings(str), ans);
}
