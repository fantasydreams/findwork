#include "310.MinimumHeightTrees.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    int n = 4;
    std::vector<std::vector<int>> edges = {{1,0},{1,2},{1,3}};
    std::vector<int> ans = {1};
    EXPECT_EQ(findMinHeightTrees(n, edges), ans);
    EXPECT_EQ(findMinHeightTrees1(n, edges), ans);
}

TEST(case_2,content)
{
    int n = 6;
    std::vector<std::vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
    std::vector<int> ans = {3, 4};
    EXPECT_EQ(findMinHeightTrees(n, edges), ans);
    EXPECT_EQ(findMinHeightTrees1(n, edges), ans);
}

TEST(case_3,content)
{
    int n = 2;
    std::vector<std::vector<int>> edges = {{0,1}};
    std::vector<int> ans = {0, 1};
    EXPECT_EQ(findMinHeightTrees(n, edges), ans);
    EXPECT_EQ(findMinHeightTrees1(n, edges), ans);
}

TEST(case_4,content)
{
    int n = 1;
    std::vector<std::vector<int>> edges = {{0}};
    std::vector<int> ans = {0};
    EXPECT_EQ(findMinHeightTrees(n, edges), ans);
    EXPECT_EQ(findMinHeightTrees1(n, edges), ans);
}

TEST(case_5,content)
{
    int n = 3;
    std::vector<std::vector<int>> edges = {{0,1}, {0,2}};
    std::vector<int> ans = {0};
    EXPECT_EQ(findMinHeightTrees(n, edges), ans);
    EXPECT_EQ(findMinHeightTrees1(n, edges), ans);
}