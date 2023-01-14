#include "34.FindFirstandLastPositionofElementinSortedArray.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> vec = {1,2,3,4,5,5,5,5,5,6,7,8,10};
    std::vector<int> res = {4, 8};
    EXPECT_EQ(searchRange(vec, 5), res);
    EXPECT_EQ(searchRange1(vec, 5), res);
}


TEST(case_2,content)
{
    std::vector<int> vec = {5,7,7,8,8,10};
    std::vector<int> res = {3, 4};
    EXPECT_EQ(searchRange(vec, 8), res);
    EXPECT_EQ(searchRange1(vec, 8), res);
}

TEST(case_3,content)
{
    std::vector<int> vec = {5,7,7,8,8,10};
    std::vector<int> res = {-1, -1};
    EXPECT_EQ(searchRange(vec, 6), res);
    EXPECT_EQ(searchRange1(vec, 6), res);
}

TEST(case_4,content)
{
    std::vector<int> vec = {};
    std::vector<int> res = {-1, -1};
    EXPECT_EQ(searchRange(vec, 0), res);
    EXPECT_EQ(searchRange1(vec, 0), res);
}