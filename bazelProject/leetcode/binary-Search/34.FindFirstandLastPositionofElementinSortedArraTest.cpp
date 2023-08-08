#include "34.FindFirstandLastPositionofElementinSortedArra.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int target = 2;
    std::vector<int> vec1 = {1,2,3}, ans = {1,1};
    EXPECT_EQ(searchRange(vec1, target), ans);
}


TEST(case_2,content)
{
    int target = 2;
    std::vector<int> vec1 = {2,2}, ans = {0,1};
    EXPECT_EQ(searchRange(vec1, target), ans);
}


TEST(case_3,content)
{
    int target = 2;
    std::vector<int> vec1 = {1,2,2,2,3,4}, ans = {1,3};
    EXPECT_EQ(searchRange(vec1, target), ans);
}