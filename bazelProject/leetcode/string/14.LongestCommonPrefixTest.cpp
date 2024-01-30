#include "gtest/gtest.h"
#include "14.LongestCommonPrefix.h"


TEST(case_1,content)
{
	std::vector<std::string> strs= {"123","123"};
    EXPECT_EQ(longestCommonPrefix(strs), "123");
    EXPECT_EQ(longestCommonPrefix_2(strs), "123");
}

TEST(case_2,content)
{
	std::vector<std::string> strs;
    EXPECT_EQ(longestCommonPrefix(strs), "");
    EXPECT_EQ(longestCommonPrefix_2(strs), "");
}

TEST(case_3,content)
{
	std::vector<std::string> strs = {"ads","a","b"};
    EXPECT_EQ(longestCommonPrefix(strs), "");
    EXPECT_EQ(longestCommonPrefix_2(strs), "");
}

TEST(case_4,content)
{
	std::vector<std::string> strs = {"ads","ad","a"};
    EXPECT_EQ(longestCommonPrefix(strs), "a");
    EXPECT_EQ(longestCommonPrefix_2(strs), "a");
}

//遗漏的边界case
TEST(case_5,content)
{
	std::vector<std::string> strs = {"ads"};
    EXPECT_EQ(longestCommonPrefix(strs), "ads");
    EXPECT_EQ(longestCommonPrefix_2(strs), "ads");
}

TEST(case_6,content)
{
	std::vector<std::string> strs= {"123","123"};
    EXPECT_EQ(longestCommonPrefix_1(strs), "123");
    EXPECT_EQ(longestCommonPrefix_2(strs), "123");
}

TEST(case_7,content)
{
	std::vector<std::string> strs;
    EXPECT_EQ(longestCommonPrefix_1(strs), "");
    EXPECT_EQ(longestCommonPrefix_2(strs), "");
}

TEST(case_8,content)
{
	std::vector<std::string> strs = {"ads","a","b"};
    EXPECT_EQ(longestCommonPrefix_1(strs), "");
    EXPECT_EQ(longestCommonPrefix_2(strs), "");
}

TEST(case_9,content)
{
	std::vector<std::string> strs = {"ads","ad","a"};
    EXPECT_EQ(longestCommonPrefix_1(strs), "a");
    EXPECT_EQ(longestCommonPrefix_2(strs), "a");
}

//遗漏的边界case
TEST(case_10,content)
{
	std::vector<std::string> strs = {"ads"};
    EXPECT_EQ(longestCommonPrefix_1(strs), "ads");
    EXPECT_EQ(longestCommonPrefix_2(strs), "ads");
}

TEST(case_11,content)
{
	std::vector<std::string> strs = {"ads",""};
    EXPECT_EQ(longestCommonPrefix_1(strs), "");
    EXPECT_EQ(longestCommonPrefix_2(strs), "");
}


int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}