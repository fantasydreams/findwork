#include "406.QueueReconstructionbyHeight.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<std::vector<int>> f = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    std::vector<std::vector<int>> g = {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}};
    EXPECT_EQ(reconstructQueue(f), g);
    EXPECT_EQ(reconstructQueue1(f), g);
}

TEST(case_2,content)
{
	std::vector<std::vector<int>> f = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    std::vector<std::vector<int>> g = {{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}};
    EXPECT_EQ(reconstructQueue(f), g);
    EXPECT_EQ(reconstructQueue1(f), g);
}