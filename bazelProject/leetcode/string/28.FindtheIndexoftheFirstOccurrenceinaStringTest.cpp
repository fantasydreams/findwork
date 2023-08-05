#include "28.FindtheIndexoftheFirstOccurrenceinaString.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
	std::string haystack = "sadbutsad", needle = "sad";
    int ans = 0;
    EXPECT_EQ(strStr(haystack, needle), ans);
    EXPECT_EQ(strStr1(haystack, needle), ans); 
    EXPECT_EQ(strKmp(haystack, needle), ans);
    EXPECT_EQ(strKmp1(haystack, needle), ans);
}

TEST(case_2,content)
{
	std::string haystack = "leetcode", needle = "leeto";
    int ans = -1;
    EXPECT_EQ(strStr(haystack, needle), ans);
    EXPECT_EQ(strStr1(haystack, needle), ans); 
    EXPECT_EQ(strKmp(haystack, needle), ans);
    EXPECT_EQ(strKmp1(haystack, needle), ans);
}

TEST(case_3,content)
{
	std::string haystack = "sharwen", needle = "wen";
    int ans = 4;
    EXPECT_EQ(strStr(haystack, needle), ans);
    EXPECT_EQ(strStr1(haystack, needle), ans); 
    EXPECT_EQ(strKmp(haystack, needle), ans);
    EXPECT_EQ(strKmp1(haystack, needle), ans);
}

TEST(case_4,content)
{
	std::string haystack = "sharwen", needle = "har";
    int ans = 1;
    EXPECT_EQ(strStr(haystack, needle), ans);
    EXPECT_EQ(strStr1(haystack, needle), ans); 
    EXPECT_EQ(strKmp(haystack, needle), ans);
    EXPECT_EQ(strKmp1(haystack, needle), ans);
}