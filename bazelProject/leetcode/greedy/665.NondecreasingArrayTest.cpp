#include "665.NondecreasingArray.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<int> f = {4,2,3};
    EXPECT_EQ(checkPossibility(f), true);
}

TEST(case_2,content)
{
	std::vector<int> f = {4,2,1};
    EXPECT_EQ(checkPossibility(f), false);
}

TEST(case_3,content)
{
	std::vector<int> f = {1,2,3,4,9,4,5,6};
    EXPECT_EQ(checkPossibility(f), true);
}

TEST(case_4,content)
{
	std::vector<int> f = {1,2,3,4,9,9,4,5,6};
    EXPECT_EQ(checkPossibility(f), false);
}

TEST(case_5,content)
{
	std::vector<int> f = {1,2,3,-1,3,4,5};
    EXPECT_EQ(checkPossibility(f), true);
}

TEST(case_6,content)
{
	std::vector<int> f = {1,2,3,3,-1,3,4,5};
    EXPECT_EQ(checkPossibility(f), true);
}

TEST(case_7,content)
{
	std::vector<int> f = {1,2,3,3,-1,-1,3,4,5};
    EXPECT_EQ(checkPossibility(f), false);
}