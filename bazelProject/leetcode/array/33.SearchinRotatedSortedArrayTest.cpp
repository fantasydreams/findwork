#include "33.SearchinRotatedSortedArray.h"
#include "gtest/gtest.h"
#include <algorithm>



TEST(case_1,content)
{
    std::vector<int> vec = {4,5,6,7,0,1,2};
    int ans = 4, target = 0;
    EXPECT_EQ(search(vec, target), ans);
    EXPECT_EQ(search1(vec, target), ans);
    EXPECT_EQ(search2(vec, target), ans);
}


TEST(case_2,content)
{
    std::vector<int> vec = {4,5,6,7,0,1,2};
    int ans = -1, target = 3;
    EXPECT_EQ(search(vec, target), ans);
    EXPECT_EQ(search1(vec, target), ans);
    EXPECT_EQ(search2(vec, target), ans);
}


TEST(case_3,content)
{
    std::vector<int> vec = {1};
    int ans = -1, target = 0;
    EXPECT_EQ(search(vec, target), ans);
    EXPECT_EQ(search1(vec, target), ans);
    EXPECT_EQ(search2(vec, target), ans);
}

TEST(case_4,content)
{
    std::vector<int> vec = {5,1,3};
    int ans = 2, target = 3;
    EXPECT_EQ(search(vec, target), ans);
    EXPECT_EQ(search1(vec, target), ans);
    EXPECT_EQ(search2(vec, target), ans);
}


TEST(case_5,content)
{
    std::vector<int> vec = {4,5,2,2,2,2,3};
    int ans = 1, target = 5;
    EXPECT_EQ(search(vec, target), ans);
    EXPECT_EQ(search2(vec, target), ans);
}


TEST(case_6, content)
{
    std::vector<int> vec = {2,3,4,5,1,1,2};
    int ans1 = 4, ans2 = 5, target = 1;
    EXPECT_EQ((search(vec, target) == ans1 || search(vec, target) == ans2), true);
    EXPECT_EQ((search2(vec, target) == ans1 || search2(vec, target) == ans2), true);
}