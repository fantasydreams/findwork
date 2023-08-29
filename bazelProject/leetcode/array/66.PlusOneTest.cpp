#include "66.PlusOne.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> empty;
    std::vector<int> ans = {1};
    EXPECT_EQ(plusOne(empty), ans);
}

TEST(case_2, content)
{
    std::vector<int> vec = {0,0,1};
    std::vector<int> ans = {2};
    EXPECT_EQ(plusOne(vec), ans);
}

TEST(case_3, content)
{
    std::vector<int> vec = {1,2,3};
    std::vector<int> ans = {1,2,4};
    EXPECT_EQ(plusOne(vec), ans);
}

TEST(case_4, content)
{
    std::vector<int> vec = {4,3,2,1};
    std::vector<int> ans = {4,3,2,2};
    EXPECT_EQ(plusOne(vec), ans);
}

TEST(case_5, content)
{
    std::vector<int> vec = {9};
    std::vector<int> ans = {1,0};
    EXPECT_EQ(plusOne(vec), ans);
}