#include "gtest/gtest.h"
#include <vector>
#include "135.Candy.h"


TEST(case_1,content)
{
	std::vector<int> vec = {2};
    EXPECT_EQ(candy(vec), 1);
    EXPECT_EQ(candy1(vec), 1);
}

TEST(case_2,content)
{
	std::vector<int> vec = {};
    EXPECT_EQ(candy(vec), 0);
    EXPECT_EQ(candy1(vec), 0);
}

TEST(case_3,content)
{
	std::vector<int> vec = {1,2};
    EXPECT_EQ(candy(vec), 3);
    EXPECT_EQ(candy1(vec), 3);
}

TEST(case_4,content)
{
	std::vector<int> vec = {1,2,2};
    EXPECT_EQ(candy(vec), 4);
    EXPECT_EQ(candy1(vec), 4);
}

TEST(case_5,content)
{
	std::vector<int> vec = {1,0,2};
    EXPECT_EQ(candy(vec), 5);
    EXPECT_EQ(candy1(vec), 5);
}

TEST(case_6,content)
{
	std::vector<int> vec = {1,3,4,5,2};
    EXPECT_EQ(candy(vec), 11);
    EXPECT_EQ(candy1(vec), 11);
}