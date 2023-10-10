#include "131.PalindromePartitioning.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
	std::string str = "aab";
    std::vector<std::vector<std::string> > res = {{"a","a","b"}, {"aa","b"}};
    EXPECT_EQ(partition(str), res);
    EXPECT_EQ(partitionDp(str), res);
    EXPECT_EQ(partitionDp1(str), res);
}


TEST(case_2,content)
{
	std::string str = "a";
    std::vector<std::vector<std::string> > res = {{"a"}};
    EXPECT_EQ(partition(str), res);
    EXPECT_EQ(partitionDp(str), res);
    EXPECT_EQ(partitionDp1(str), res);
}

TEST(case_3,content)
{
	std::string str = "abaaba";
    std::vector<std::vector<std::string> > res = {
        {"a","b","a","a","b","a"}, 
        {"a","b","a","aba"},
        {"a","b","aa","b","a"},
        {"a","baab","a"},
        {"aba","a","b","a"}, 
        {"aba", "aba"}, 
        {"abaaba"}
    };
    EXPECT_EQ(partition(str), res);
    EXPECT_EQ(partitionDp(str), res);
    EXPECT_EQ(partitionDp1(str), res);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}