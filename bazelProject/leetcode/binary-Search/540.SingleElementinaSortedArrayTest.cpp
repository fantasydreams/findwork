#include "540.SingleElementinaSortedArray.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1, content)
{
    std::vector<int> vec = {1,1,0};
    EXPECT_EQ(singleNonDuplicate(vec), 0);
    EXPECT_EQ(singleNonDuplicate1(vec), 0);
}

TEST(case_2, content)
{
    std::vector<int> vec = {0};
    EXPECT_EQ(singleNonDuplicate(vec), 0);
    EXPECT_EQ(singleNonDuplicate1(vec), 0);
}

TEST(case_3, content)
{
    std::vector<int> vec = {0,1,1};
    EXPECT_EQ(singleNonDuplicate(vec), 0);
    EXPECT_EQ(singleNonDuplicate1(vec), 0);
}

TEST(case_4, content)
{
    std::vector<int> vec = {1,1,2,3,3,4,4,8,8};
    EXPECT_EQ(singleNonDuplicate(vec), 2);
    EXPECT_EQ(singleNonDuplicate1(vec), 2);
}

TEST(case_5, content)
{
    std::vector<int> vec = {3,3,7,7,10,11,11};
    EXPECT_EQ(singleNonDuplicate(vec), 10);
    EXPECT_EQ(singleNonDuplicate1(vec), 10);
}


TEST(case_6, content)
{
    std::vector<int> vec = {1,1,2,3,3};
    EXPECT_EQ(singleNonDuplicate(vec), 2);
    EXPECT_EQ(singleNonDuplicate1(vec), 2);
}