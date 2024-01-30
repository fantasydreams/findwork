#include "151.ReverseWordsinaString.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::string s = "the sky is blue";
    std::string ans = "blue is sky the";
    EXPECT_EQ(reverseWords(s), ans);
    EXPECT_EQ(reverseWords1(s), ans);
    EXPECT_EQ(reverseWords2(s), ans);
}


TEST(case_2, content) {
    std::string s = "  ";
    std::string ans = "";
    EXPECT_EQ(reverseWords(s), ans);
    EXPECT_EQ(reverseWords1(s), ans);
    EXPECT_EQ(reverseWords2(s), ans);
}

TEST(case_3, content) {
    std::string s = "  hello world  ";
    std::string ans = "world hello";
    EXPECT_EQ(reverseWords(s), ans);
    EXPECT_EQ(reverseWords1(s), ans);
    EXPECT_EQ(reverseWords2(s), ans);
}


TEST(case_4, content) {
    std::string s = "a good   example";
    std::string ans = "example good a";
    EXPECT_EQ(reverseWords(s), ans);
    EXPECT_EQ(reverseWords1(s), ans);
    EXPECT_EQ(reverseWords2(s), ans);
}