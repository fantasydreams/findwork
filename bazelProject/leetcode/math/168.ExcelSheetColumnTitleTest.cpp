#include "168.ExcelSheetColumnTitle.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    // int col = 0;
    // std::string ans = "0";
    // EXPECT_EQ(convertToTitle(col), ans);
}

TEST(case_2,content)
{
    int col = 1;
    std::string ans = "A";
    EXPECT_EQ(convertToTitle(col), ans);
    EXPECT_EQ(convertToTitle1(col), ans); 
}

TEST(case_3,content)
{
    int col = 26;
    std::string ans = "Z";
    EXPECT_EQ(convertToTitle(col), ans);
    EXPECT_EQ(convertToTitle1(col), ans); 
}

TEST(case_4,content)
{
    int col = 27;
    std::string ans = "AA";
    EXPECT_EQ(convertToTitle(col), ans);
    EXPECT_EQ(convertToTitle1(col), ans); 
}

TEST(case_5,content)
{
    int col = 28;
    std::string ans = "AB";
    EXPECT_EQ(convertToTitle(col), ans);
    EXPECT_EQ(convertToTitle1(col), ans); 
}

TEST(case_6,content)
{
    int col = 701;
    std::string ans = "ZY";
    EXPECT_EQ(convertToTitle(col), ans);
    EXPECT_EQ(convertToTitle1(col), ans); 
}