#include "gtest/gtest.h"
#include <vector>
#include "135.Candy.h"


TEST(case_1,content)
{
	std::vector<int> vec = {2};
    EXPECT_EQ(candy(vec), 1);
}

TEST(case_2,content)
{
	std::vector<int> vec = {};
    EXPECT_EQ(candy(vec), 0);
}

TEST(case_3,content)
{
	std::vector<int> vec = {1,2};
    EXPECT_EQ(candy(vec), 2);
}

TEST(case_4,content)
{
	std::vector<int> vec = {1,2,2};
    EXPECT_EQ(candy(vec), 4);
}

TEST(case_5,content)
{
	std::vector<int> vec = {1,0,2};
    EXPECT_EQ(candy(vec), 5);
}