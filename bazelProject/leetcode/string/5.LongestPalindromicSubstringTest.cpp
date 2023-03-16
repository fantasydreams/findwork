#include "gtest/gtest.h"
#include "5.LongestPalindromicSubstring.h"


//奇数的情况
TEST(case_1,content)
{
	std::string str= "babad";
    EXPECT_EQ(longestPalindrome(str), "bab");
    EXPECT_EQ(longestPalindromeWithoutAsistant(str), "bab");
    EXPECT_EQ(longestPalindromeWithDP(str), "bab");
    EXPECT_EQ(longestPalindromeManacher(str), "bab");
    EXPECT_EQ(longestPalindromeManacher1(str), "bab");
}


//偶数的情况
TEST(case_2,content)
{
	std::string str= "cbbd";
    EXPECT_EQ(longestPalindrome(str), "bb");
    EXPECT_EQ(longestPalindromeWithoutAsistant(str), "bb");
    EXPECT_EQ(longestPalindromeWithDP(str), "bb");
    EXPECT_EQ(longestPalindromeManacher(str), "bb");
    EXPECT_EQ(longestPalindromeManacher1(str), "bb");
}


//一个字符
TEST(case_3,content)
{
	std::string str= "a";
    EXPECT_EQ(longestPalindrome(str), "a");
    EXPECT_EQ(longestPalindromeWithoutAsistant(str), "a");
    EXPECT_EQ(longestPalindromeWithDP(str), "a");
    EXPECT_EQ(longestPalindromeManacher(str), "a");
    EXPECT_EQ(longestPalindromeManacher1(str), "a");
}


TEST(case_4,content)
{
	std::string str= "ac";
    EXPECT_EQ(longestPalindrome(str), "a");
    EXPECT_EQ(longestPalindromeWithoutAsistant(str), "a");
    EXPECT_EQ(longestPalindromeWithDP(str), "a");
    EXPECT_EQ(longestPalindromeManacher(str), "a");
    EXPECT_EQ(longestPalindromeManacher1(str), "a");
}

//字符串整个串是回文
// "aaaaa"

TEST(case_5,content)
{
	std::string str= "aaaaa";
    EXPECT_EQ(longestPalindrome(str), "aaaaa");
    EXPECT_EQ(longestPalindromeWithoutAsistant(str), "aaaaa");
    EXPECT_EQ(longestPalindromeWithDP(str), "aaaaa");
    EXPECT_EQ(longestPalindromeManacher(str), "aaaaa");
    EXPECT_EQ(longestPalindromeManacher1(str), "aaaaa");
}


// "xaabacxcabaaxcabaax"
TEST(case_6,content)
{
	std::string str= "xaabacxcabaaxcabaax";
    EXPECT_EQ(longestPalindrome(str), "xaabacxcabaax");
    EXPECT_EQ(longestPalindromeWithoutAsistant(str), "xaabacxcabaax");
    EXPECT_EQ(longestPalindromeWithDP(str), "xaabacxcabaax");
    EXPECT_EQ(longestPalindromeManacher(str), "xaabacxcabaax");
    EXPECT_EQ(longestPalindromeManacher1(str), "xaabacxcabaax");
}

//"cbcdcbedcbc"
TEST(case_7,content)
{
	std::string str= "cbcdcbedcbc";
    EXPECT_EQ(longestPalindrome(str), "bcdcb");
    EXPECT_EQ(longestPalindromeWithoutAsistant(str), "bcdcb");
    EXPECT_EQ(longestPalindromeWithDP(str), "bcdcb");
    EXPECT_EQ(longestPalindromeManacher(str), "bcdcb");
    EXPECT_EQ(longestPalindromeManacher1(str), "bcdcb");
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}