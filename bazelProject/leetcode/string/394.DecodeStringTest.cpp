#include "gtest/gtest.h"
#include "394.DecodeString.h"


TEST(case_1,content)
{
	std::string str= "2[a]2[bc]";
    EXPECT_EQ(decodeString(str), "aabcbc");
}

TEST(case_2,content)
{
	std::string str= "2[a]2[bc3[de]]";
    EXPECT_EQ(decodeString(str), "aabcdededebcdedede");
}


TEST(case_3,content)
{
	std::string str= "3[a2[c]]";
    EXPECT_EQ(decodeString(str), "accaccacc");
}


TEST(case_4,content)
{
	std::string str= "2[abc]3[cd]ef";
    EXPECT_EQ(decodeString(str), "abcabccdcdcdef");
}


TEST(case_5,content)
{
	std::string str= "abc3[cd]xyz";
    EXPECT_EQ(decodeString(str), "abccdcdcdxyz");
}

TEST(case_6,content)
{
	std::string str= "100[leetcode]";
    EXPECT_EQ(decodeString(str), "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode");
}



//这种嵌套加嵌套的方式容易被设计用例忽略
TEST(case_7,content)
{
	std::string str= "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    EXPECT_EQ(decodeString(str), "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef");
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}