#include "125.ValidPalindrome.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::string str = "";
    bool ans = true;

    EXPECT_EQ(isPalindrome(str), ans);
}

TEST(case_2, content) {
    std::string str = "1";
    bool ans = true;

    EXPECT_EQ(isPalindrome(str), ans);
}


TEST(case_6, content) {
    std::string str = "11";
    bool ans = true;

    EXPECT_EQ(isPalindrome(str), ans);
}


TEST(case_3, content) {
    std::string str = "121";
    bool ans = true;

    EXPECT_EQ(isPalindrome(str), ans);
}

TEST(case_4, content) {
    std::string str = "1221";
    bool ans = true;

    EXPECT_EQ(isPalindrome(str), ans);
}

TEST(case_5, content) {
    std::string str = "112";
    bool ans = false;

    EXPECT_EQ(isPalindrome(str), ans);
}