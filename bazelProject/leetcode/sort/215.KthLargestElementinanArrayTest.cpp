#include "215.KthLargestElementinanArray.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> vec1 = {1,2,3};
    EXPECT_EQ(findKthLargest(vec1, 2), 2);
}

TEST(case_2,content)
{
    std::vector<int> vec1 = {1};
    EXPECT_EQ(findKthLargest(vec1, 1), 1);
}

TEST(case_3,content)
{
    std::vector<int> vec1 = {3,2,1,5,6,4};
    EXPECT_EQ(findKthLargest(vec1, 2), 5);
}

TEST(case_4,content)
{
    std::vector<int> vec1 = {3,2,3,1,2,4,5,5,6};
    EXPECT_EQ(findKthLargest(vec1, 4), 4);
}