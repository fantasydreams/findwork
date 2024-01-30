#include "58.LengthofLastWord.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::string str;
    int ans = 0;
    EXPECT_EQ(lengthOfLastWord(str), ans);
    EXPECT_EQ(lengthOfLastWordStdString(str), ans);
}

TEST(case_2,content)
{
    std::string str = "123 442";
    int ans = 3;
    EXPECT_EQ(lengthOfLastWord(str), ans);
    EXPECT_EQ(lengthOfLastWordStdString(str), ans);
}

TEST(case_3,content)
{
    std::string str = "123 442 ";
    int ans = 3;
    EXPECT_EQ(lengthOfLastWord(str), ans);
    EXPECT_EQ(lengthOfLastWordStdString(str), ans);
}

TEST(case_4,content)
{
    std::string str = "442 ";
    int ans = 3;
    EXPECT_EQ(lengthOfLastWord(str), ans);
    EXPECT_EQ(lengthOfLastWordStdString(str), ans);
}

TEST(case_5,content)
{
    std::string str = " 442 ";
    int ans = 3;
    EXPECT_EQ(lengthOfLastWord(str), ans);
    EXPECT_EQ(lengthOfLastWordStdString(str), ans);
}