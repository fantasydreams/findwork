#include "214.ShortestPalindrome.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::string s = "aacecaaa";
    std::string sAns = "aaacecaaa";
    EXPECT_EQ(shortestPalindrome(s), sAns);
    EXPECT_EQ(shortestPalindromeDp(s), sAns);
    EXPECT_EQ(shortestPalindromeDoublePointer(s), sAns);
    EXPECT_EQ(shortestPalindromeManacher(s), sAns);
}


TEST(case_2, content) {
    std::string s = "abcd";
    std::string sAns = "dcbabcd";
    EXPECT_EQ(shortestPalindrome(s), sAns);
    EXPECT_EQ(shortestPalindromeDp(s), sAns);
    EXPECT_EQ(shortestPalindromeDoublePointer(s), sAns);
    EXPECT_EQ(shortestPalindromeManacher(s), sAns);
}


TEST(case_3, content) {
    std::string s = "adcba";
    std::string sAns = "abcdadcba";
    EXPECT_EQ(shortestPalindrome(s), sAns);
    EXPECT_EQ(shortestPalindromeDp(s), sAns);
    EXPECT_EQ(shortestPalindromeDoublePointer(s), sAns);
    EXPECT_EQ(shortestPalindromeManacher(s), sAns);
}