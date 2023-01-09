#include "167.TwoSumII-InputArrayIsSorted.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<int> f = {1,2};
    std::vector<int> g = {1,2};
    EXPECT_EQ(twoSum(f, 3), g);
}

TEST(case_2,content)
{
	std::vector<int> f = {1,2,3};
    std::vector<int> g = {1,3};
    EXPECT_EQ(twoSum(f, 4), g);
}

TEST(case_3,content)
{
	std::vector<int> f = {2,7,11,15};
    std::vector<int> g = {1,2};
    EXPECT_EQ(twoSum(f, 9), g);
}

TEST(case_4,content)
{
	std::vector<int> f = {2,3,4};
    std::vector<int> g = {1,3};
    EXPECT_EQ(twoSum(f, 6), g);
}

TEST(case_5,content)
{
	std::vector<int> f = {-1,0};
    std::vector<int> g = {1,2};
    EXPECT_EQ(twoSum(f, -1), g);
}


