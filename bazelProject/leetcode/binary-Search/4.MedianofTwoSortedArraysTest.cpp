#include "4.MedianofTwoSortedArrays.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> vec1 = {1,2,3};
    std::vector<int> vec2 = {4,5,6};
    EXPECT_EQ(findMedianSortedArrays(vec1, vec2), 3.5);
    EXPECT_EQ(findMedianSortedArrays1(vec1, vec2), 3.5);
    EXPECT_EQ(findMedianSortedArrays2(vec1, vec2), 3.5);
}

TEST(case_2,content)
{
    std::vector<int> vec1 = {1,3};
    std::vector<int> vec2 = {2};
    EXPECT_EQ(findMedianSortedArrays(vec1, vec2), 2);
    EXPECT_EQ(findMedianSortedArrays1(vec1, vec2), 2);
    EXPECT_EQ(findMedianSortedArrays2(vec1, vec2), 2);
}

TEST(case_4,content)
{
    std::vector<int> vec1 = {1, 2};
    std::vector<int> vec2 = {3, 4};
    EXPECT_EQ(findMedianSortedArrays(vec1, vec2), 2.5);
    EXPECT_EQ(findMedianSortedArrays1(vec1, vec2), 2.5);
    EXPECT_EQ(findMedianSortedArrays2(vec1, vec2), 2.5);
}

TEST(case_5,content)
{
    std::vector<int> vec1 = {};
    std::vector<int> vec2 = {1};
    EXPECT_EQ(findMedianSortedArrays(vec1, vec2), 1);
    EXPECT_EQ(findMedianSortedArrays1(vec1, vec2), 1);
    EXPECT_EQ(findMedianSortedArrays2(vec1, vec2), 1);
}

TEST(case_6,content)
{
    std::vector<int> vec1 = {3};
    std::vector<int> vec2 = {-2, -1};
    EXPECT_EQ(findMedianSortedArrays(vec1, vec2), -1);
    EXPECT_EQ(findMedianSortedArrays1(vec1, vec2), -1);
    EXPECT_EQ(findMedianSortedArrays2(vec1, vec2), -1);
}

TEST(case_7,content)
{
    std::vector<int> vec1 = {0,0,0,0,0};
    std::vector<int> vec2 = {-1,0,0,0,0,0,1};
    EXPECT_EQ(findMedianSortedArrays(vec1, vec2), 0);
    EXPECT_EQ(findMedianSortedArrays1(vec1, vec2), 0);
    EXPECT_EQ(findMedianSortedArrays2(vec1, vec2), 0);
}