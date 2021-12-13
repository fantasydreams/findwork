#include "gtest/gtest.h"
#include "arraycomm.h"
#include "4.MedianOfTwoSortedArrays.h"

TEST(case_1,content)
{
	std::vector<int> vec1 = {};
    std::vector<int> vec2 = {0,1};
    EXPECT_EQ(findMedianSortedArrays(vec1,vec2), 0.5);
    EXPECT_EQ(findMedianSortedArrays1(vec1,vec2), 0.5);
    EXPECT_EQ(findMedianSortedArraysBinarySearch(vec1,vec2), 0.5);
    EXPECT_EQ(findMedianSortedArraysBinarySearchNotRecursion(vec1,vec2), 0.5);
}

TEST(case_2,content)
{
	std::vector<int> vec1 = {1};
    std::vector<int> vec2 = {2,3};
    EXPECT_EQ(findMedianSortedArrays(vec1,vec2), 2);
    EXPECT_EQ(findMedianSortedArrays1(vec1,vec2), 2);
    EXPECT_EQ(findMedianSortedArraysBinarySearch(vec1,vec2), 2);
    EXPECT_EQ(findMedianSortedArraysBinarySearchNotRecursion(vec1,vec2), 2);
}

TEST(case_3,content)
{
	std::vector<int> vec1 = {1,3};
    std::vector<int> vec2 = {2,4};
    EXPECT_EQ(findMedianSortedArrays(vec1,vec2), 2.5);
    EXPECT_EQ(findMedianSortedArrays1(vec1,vec2), 2.5);
    EXPECT_EQ(findMedianSortedArraysBinarySearch(vec1,vec2), 2.5);
    EXPECT_EQ(findMedianSortedArraysBinarySearchNotRecursion(vec1,vec2), 2.5);
}

TEST(case_4,content)
{
	std::vector<int> vec1 = {3};
    std::vector<int> vec2 = {1,5};
    EXPECT_EQ(findMedianSortedArrays(vec1,vec2), 3);
    EXPECT_EQ(findMedianSortedArrays1(vec1,vec2), 3);
    EXPECT_EQ(findMedianSortedArraysBinarySearch(vec1,vec2), 3);
    EXPECT_EQ(findMedianSortedArraysBinarySearchNotRecursion(vec1,vec2), 3);
}

TEST(case_5,content)
{
	std::vector<int> vec1 = {1,3,5};
    std::vector<int> vec2 = {};
    EXPECT_EQ(findMedianSortedArrays(vec1,vec2), 3);
    EXPECT_EQ(findMedianSortedArrays1(vec1,vec2), 3);
    EXPECT_EQ(findMedianSortedArraysBinarySearch(vec1,vec2), 3);
    EXPECT_EQ(findMedianSortedArraysBinarySearchNotRecursion(vec1,vec2), 3);
}




int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}