#include "205.IsomorphicStrings.h"
#include "gtest/gtest.h"


//奇数的情况
TEST(case_1,content)
{
	std::string s = "egg", t = "add";
    bool ans = true;
    EXPECT_EQ(isIsomorphic(s, t), ans);
}

TEST(case_2,content)
{
	std::string s = "foo", t = "bar";
    bool ans = false;
    EXPECT_EQ(isIsomorphic(s, t), ans);
}

TEST(case_3,content)
{
	std::string s = "paper", t = "title";
    bool ans = true;
    EXPECT_EQ(isIsomorphic(s, t), ans);
}

TEST(case_4,content)
{
	std::string s = "badc", t = "baba";
    bool ans = false;
    EXPECT_EQ(isIsomorphic(s, t), ans);
}