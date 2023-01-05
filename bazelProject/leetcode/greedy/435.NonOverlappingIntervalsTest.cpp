#include "gtest/gtest.h"
#include <vector>
#include "435.NonOverlappingIntervals.h"


TEST(case_1,content)
{
	std::vector<std::vector<int>> vec = {{1,5},{2,5},{3,4},{4,5}};
    EXPECT_EQ(eraseOverlapIntervals(vec), 2);
}

TEST(case_2,content)
{
	std::vector<std::vector<int>> vec = {{1,2},{2,3},{3,4},{1,3}};
    EXPECT_EQ(eraseOverlapIntervals(vec), 1);
}


TEST(case_3,content)
{
	std::vector<std::vector<int>> vec = {{1,2},{1,2},{1,2}};
    EXPECT_EQ(eraseOverlapIntervals(vec), 2);
}

TEST(case_4,content)
{
	std::vector<std::vector<int>> vec = {{1,2},{2,4}};
    EXPECT_EQ(eraseOverlapIntervals(vec), 0);
}

TEST(case_5,content)
{
	std::vector<std::vector<int>> vec = {{1,2}};
    EXPECT_EQ(eraseOverlapIntervals(vec), 0);
}

TEST(case_6,content)
{
	std::vector<std::vector<int>> vec = {};
    EXPECT_EQ(eraseOverlapIntervals(vec), 0);
}