#include "242.ValidAnagram.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
	std::string s = "anagram", t = "nagaram";
    bool ans = true;
    EXPECT_EQ(isAnagram(s,t), ans);
    EXPECT_EQ(isAnagram1(s,t), ans);
    EXPECT_EQ(isAnagram2(s,t), ans);
}


TEST(case_2,content)
{
	std::string s = "rat", t = "car";
    bool ans = false;
    EXPECT_EQ(isAnagram(s,t), ans);
    EXPECT_EQ(isAnagram1(s,t), ans);
    EXPECT_EQ(isAnagram2(s,t), ans);
}