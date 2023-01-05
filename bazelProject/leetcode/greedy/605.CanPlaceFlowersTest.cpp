#include "605.CanPlaceFlowers.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<int> f = {1,0,1};
    EXPECT_EQ(canPlaceFlowers(f,1), false);
}

TEST(case_2,content)
{
	std::vector<int> f = {1,0,1};
    EXPECT_EQ(canPlaceFlowers(f,0), true);
}

TEST(case_3,content)
{
	std::vector<int> f = {1,0,0,0,1};
    EXPECT_EQ(canPlaceFlowers(f,1), true);
}

TEST(case_4,content)
{
	std::vector<int> f = {1,0,0,0,1};
    EXPECT_EQ(canPlaceFlowers(f, 2), false);
}