#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include "62.UniquePaths.h"

TEST(case_1, content)
{
    int m = 1, n = 1, ans = 1;
    EXPECT_EQ(uniquePaths(m, n), ans);
    EXPECT_EQ(uniquePathsDFS(m, n), ans);
}

TEST(case_2, content)
{
    int m = 2, n = 2, ans = 2;
    EXPECT_EQ(uniquePaths(m, n), ans);
    EXPECT_EQ(uniquePathsDFS(m, n), ans);
}


TEST(case_3, content)
{
    int m = 2, n = 1, ans = 1;
    EXPECT_EQ(uniquePaths(m, n), ans);
    EXPECT_EQ(uniquePathsDFS(m, n), ans);
}

TEST(case_7, content)
{
    int m = 1, n = 3, ans = 1;
    EXPECT_EQ(uniquePaths(m, n), ans);
    EXPECT_EQ(uniquePathsDFS(m, n), ans);
}

TEST(case_4, content)
{
    int m = 3, n = 2, ans = 3;
    EXPECT_EQ(uniquePaths(m, n), ans);
    EXPECT_EQ(uniquePathsDFS(m, n), ans);
}

TEST(case_5, content)
{
    int m = 2, n = 3, ans = 3;
    EXPECT_EQ(uniquePaths(m, n), ans);
    EXPECT_EQ(uniquePathsDFS(m, n), ans);
}

TEST(case_6, content)
{
    int m = 3, n = 7, ans = 28
    ;
    EXPECT_EQ(uniquePaths(m, n), ans);
    EXPECT_EQ(uniquePathsDFS(m, n), ans);
}