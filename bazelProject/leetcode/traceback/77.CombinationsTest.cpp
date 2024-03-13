#include "77.Combinations.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int n = 4, k = 2;
    vector<vector<int>> res = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
    EXPECT_EQ(combine(n, k), res);
    EXPECT_EQ(combine1(n, k), res);
    EXPECT_EQ(combine2(n, k), res);
    EXPECT_EQ(combine3(n, k), res);
}

TEST(case_2,content)
{
    int n = 1, k = 1;
    vector<vector<int>> res = {{1}};
    EXPECT_EQ(combine(n, k), res);
    EXPECT_EQ(combine1(n, k), res);
    EXPECT_EQ(combine2(n, k), res);
    EXPECT_EQ(combine3(n, k), res);
}

TEST(case_3,content)
{
    int n = 5, k = 1;
    vector<vector<int>> res = {{1}, {2}, {3}, {4}, {5}};
    EXPECT_EQ(combine(n, k), res);
    EXPECT_EQ(combine1(n, k), res);
    EXPECT_EQ(combine2(n, k), res);
    EXPECT_EQ(combine3(n, k), res);
}

TEST(case_4,content)
{
    int n = 5, k = 3;
    vector<vector<int>> res = {{1,2,3}, {1,2,4},{1,2,5}, {1,3,4}, {1, 3,5}, {1,4,5}, {2,3,4}, {2,3,5}, {2,4,5}, {3,4,5}};
    EXPECT_EQ(combine(n, k), res);
    EXPECT_EQ(combine1(n, k), res);
    EXPECT_EQ(combine2(n, k), res);
    EXPECT_EQ(combine3(n, k), res);
}