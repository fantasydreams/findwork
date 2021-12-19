#include "9.PalindromeNumber.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    EXPECT_EQ(isPalindromeByString(-1), false);
    EXPECT_EQ(isPalindrome(-1), false);
    EXPECT_EQ(isPalindromeOptimise(-1), false);
}

TEST(case_2,content)
{
    EXPECT_EQ(isPalindromeByString(10), false);
    EXPECT_EQ(isPalindrome(10), false);
    EXPECT_EQ(isPalindromeOptimise(10), false);
}


TEST(case_3,content)
{
    EXPECT_EQ(isPalindromeByString(121), true);
    EXPECT_EQ(isPalindrome(121), true);
    EXPECT_EQ(isPalindromeOptimise(121), false);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}