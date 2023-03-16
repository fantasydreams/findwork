#include "3.LongestSubstringWithoutRepeatingCharacters.h"
#include "gtest/gtest.h"


//正常
TEST(case_1,content)
{
	std::string str = "abcabcbb";
    EXPECT_EQ(lengthOfLongestSubstring(str), 3);
    EXPECT_EQ(lengthOfLongestSubstringWithSet(str), 3);
    EXPECT_EQ(lengthOfLongestSubstringWithSet1(str), 3);
}

//空串
TEST(case_2,content)
{
	std::string str = "";
    EXPECT_EQ(lengthOfLongestSubstring(str), 0);
    EXPECT_EQ(lengthOfLongestSubstringWithSet(str), 0);
    EXPECT_EQ(lengthOfLongestSubstringWithSet1(str), 0);
}

// repeat
TEST(case_3,content)
{
	std::string str = "aaaaaa";
    EXPECT_EQ(lengthOfLongestSubstring(str), 1);
    EXPECT_EQ(lengthOfLongestSubstringWithSet(str), 1);
    EXPECT_EQ(lengthOfLongestSubstringWithSet1(str), 1);
}

//waaaaaw
TEST(case_4,content)
{
	std::string str = "waaaaaw";
    EXPECT_EQ(lengthOfLongestSubstring(str), 2);
    EXPECT_EQ(lengthOfLongestSubstringWithSet(str), 2);
    EXPECT_EQ(lengthOfLongestSubstringWithSet1(str), 2);
}

//pwwkew
TEST(case_5,content)
{
	std::string str = "pwwkew";
    EXPECT_EQ(lengthOfLongestSubstring(str), 3);
    EXPECT_EQ(lengthOfLongestSubstringWithSet(str), 3);
    EXPECT_EQ(lengthOfLongestSubstringWithSet1(str), 3);
}

//"dvdf"
TEST(case_6,content)
{
	std::string str = "dvdf";
    EXPECT_EQ(lengthOfLongestSubstring(str), 3);
    EXPECT_EQ(lengthOfLongestSubstringWithSet(str), 3);
    EXPECT_EQ(lengthOfLongestSubstringWithSet1(str), 3);
}



//"tmmzuxt"
TEST(case_7,content)
{
	std::string str = "tmmzuxt";
    EXPECT_EQ(lengthOfLongestSubstring(str), 5);
    EXPECT_EQ(lengthOfLongestSubstringWithSet(str), 5);
    EXPECT_EQ(lengthOfLongestSubstringWithSet1(str), 5);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}