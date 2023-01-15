#include "154.FindMinimuminRotatedSortedArrayII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> vec = {1,0};
    EXPECT_EQ(findMin(vec), 0);
    EXPECT_EQ(findMin1(vec), 0);
}

TEST(case_2,content)
{
    std::vector<int> vec = {1,0, 1};
    EXPECT_EQ(findMin(vec), 0);
    EXPECT_EQ(findMin1(vec), 0);
}

TEST(case_3,content)
{
    std::vector<int> vec = {1,3,5};
    EXPECT_EQ(findMin(vec), 1);
    EXPECT_EQ(findMin1(vec), 1);
}

TEST(case_4,content)
{
    std::vector<int> vec = {2,2,2,0,1};
    EXPECT_EQ(findMin(vec), 0);
    EXPECT_EQ(findMin1(vec), 0);
}

TEST(case_5,content)
{
    std::vector<int> vec = {0,1};
    EXPECT_EQ(findMin(vec), 0);
    EXPECT_EQ(findMin1(vec), 0);
}