#include "452.MinimumNumberofArrowstoBurstBalloons.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<std::vector<int>> g = {{1,2}, {3,4},{2,5}, {4,5}};
    EXPECT_EQ(findMinArrowShots(g), 2);
    EXPECT_EQ(findMinArrowShots2(g), 2);
    EXPECT_EQ(findMinArrowShots3(g), 2);
    EXPECT_EQ(findMinArrowShots4(g), 2);
}

TEST(case_2,content)
{
	std::vector<std::vector<int>> g = {{10,16},{2,8},{1,6},{7,12}};
    EXPECT_EQ(findMinArrowShots(g), 2);
    EXPECT_EQ(findMinArrowShots2(g), 2);
    EXPECT_EQ(findMinArrowShots3(g), 2);
    EXPECT_EQ(findMinArrowShots4(g), 2);
}

TEST(case_3,content)
{
	std::vector<std::vector<int>> g = {{1,2},{3,4},{5,6},{7,8}};
    EXPECT_EQ(findMinArrowShots(g), 4);
    EXPECT_EQ(findMinArrowShots2(g), 4);
    EXPECT_EQ(findMinArrowShots3(g), 4);
    EXPECT_EQ(findMinArrowShots4(g), 4);
}

TEST(case_4,content)
{
	std::vector<std::vector<int>> g = {{1,2},{2,3},{3,4},{4,5}};
    EXPECT_EQ(findMinArrowShots(g), 2);
    EXPECT_EQ(findMinArrowShots2(g), 2);
    EXPECT_EQ(findMinArrowShots3(g), 2);
    EXPECT_EQ(findMinArrowShots4(g), 2);
}


TEST(case_5,content)
{
	std::vector<std::vector<int>> g = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    EXPECT_EQ(findMinArrowShots(g), 2);
    EXPECT_EQ(findMinArrowShots2(g), 2);
    EXPECT_EQ(findMinArrowShots3(g), 2);
    EXPECT_EQ(findMinArrowShots4(g), 2);
}