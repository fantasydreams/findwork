#include "41.FirstMissingPositive.h"
#include "gtest/gtest.h"
#include <vector>

TEST(case_1, content)
{
    int ans = 3;
    std::vector<int> vec = {1,2,0};
    EXPECT_EQ(firstMissingPositive(vec), ans);
}


TEST(case_2, content)
{
    int ans = 2;
    std::vector<int> vec = {3,4,-1,1};
    EXPECT_EQ(firstMissingPositive(vec), ans);
}

TEST(case_3, content)
{
    int ans = 1;
    std::vector<int> vec = {7,8,9,11,12};
    EXPECT_EQ(firstMissingPositive(vec), ans);
}


TEST(case_4, content)
{
    int ans = 3;
    std::vector<int> vec = {-1,4,2,1,9,10};
    EXPECT_EQ(firstMissingPositive(vec), ans);
}

TEST(case_5, content)
{
    int ans = 2;
    std::vector<int> vec = {1,1};
    EXPECT_EQ(firstMissingPositive(vec), ans);
}