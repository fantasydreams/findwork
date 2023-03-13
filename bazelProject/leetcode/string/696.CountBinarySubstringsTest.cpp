#include "696.CountBinarySubstrings.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
	std::string str= "00110011";
    int ans = 6;
    EXPECT_EQ(countBinarySubstrings(str), ans);
}

TEST(case_2,content)
{
	std::string str= "10101";
    int ans = 4;
    EXPECT_EQ(countBinarySubstrings(str), ans);
}
