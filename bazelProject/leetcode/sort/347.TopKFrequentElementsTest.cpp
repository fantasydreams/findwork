#include "347.TopKFrequentElements.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> vec1 = {1,2,2,3};
    std::vector<int> vec2 = {2,3};
    EXPECT_EQ(topKFrequent(vec1, 2), vec2);
}

TEST(case_2,content)
{
    std::vector<int> vec1 = {1,1,1,2,2,3};
    std::vector<int> vec2 = {1,2};
    EXPECT_EQ(topKFrequent(vec1, 2), vec2);
}

TEST(case_3,content)
{
    std::vector<int> vec1 = {1};
    std::vector<int> vec2 = {1};
    EXPECT_EQ(topKFrequent(vec1, 1), vec2);
}