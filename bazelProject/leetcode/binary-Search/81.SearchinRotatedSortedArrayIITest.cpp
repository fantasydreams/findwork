#include "81.SearchinRotatedSortedArrayII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> vec = {1,2,3,4,5,5,5,5,5,6,7,8,10,1};
    EXPECT_EQ(search(vec, 5), true);
    EXPECT_EQ(search1(vec, 5), true);
}

TEST(case_2,content)
{
    std::vector<int> vec = {1,2,3,4,5,5,5,5,5,6,7,8,10,1};
    EXPECT_EQ(search(vec, 1), true);
    EXPECT_EQ(search1(vec, 1), true);
}

TEST(case_3,content)
{
    std::vector<int> vec = {2,5,6,0,0,1,2};
    EXPECT_EQ(search(vec, 0), true);
    EXPECT_EQ(search1(vec, 0), true);
}

TEST(case_4,content)
{
    std::vector<int> vec = {2,5,6,0,0,1,2};
    EXPECT_EQ(search(vec, 3), false);
    EXPECT_EQ(search1(vec, 3), false);
}


TEST(case_5,content)
{
    std::vector<int> vec = {1,0,1,1,1};
    EXPECT_EQ(search(vec, 3), false);
    EXPECT_EQ(search1(vec, 3), false);
}

TEST(case_6,content)
{
    std::vector<int> vec = {2,2,2,2,3,2};
    EXPECT_EQ(search(vec, 3), true);
    EXPECT_EQ(search1(vec, 3), true);
}

TEST(case_7,content)
{
    std::vector<int> vec = {2,3,2,2,2,2};
    EXPECT_EQ(search(vec, 3), true);
    EXPECT_EQ(search1(vec, 3), true);
}