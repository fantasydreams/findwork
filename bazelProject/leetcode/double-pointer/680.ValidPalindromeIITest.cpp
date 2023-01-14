
#include "680.ValidPalindromeII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string s = "abccba";
    EXPECT_EQ(validPalindrome(s), true);
}

TEST(case_2,content)
{
    std::string s = "a";
    EXPECT_EQ(validPalindrome(s), true);
}

TEST(case_3,content)
{
    std::string s = "ab";
    EXPECT_EQ(validPalindrome(s), true);
}

TEST(case_4,content)
{
    std::string s = "abc";
    EXPECT_EQ(validPalindrome(s), false);
}


TEST(case_5,content)
{
    std::string s = "abca";
    EXPECT_EQ(validPalindrome(s), true);
}

TEST(case_6,content)
{
    std::string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    EXPECT_EQ(validPalindrome(s), true);
}

TEST(case_7,content)
{
    std::string s = "eddboebddcaacddkbebdde";
    EXPECT_EQ(validPalindrome(s), false);
}