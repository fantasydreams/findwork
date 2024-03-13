#include "63.UniquePathsII.h"
#include "gtest/gtest.h"
#include <cstddef>
#include <vector>
#include <cstdlib>
#include <cmath>

TEST(case_1, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 0, 0},
        {0, 1 ,0},
        {0, 0, 0}
    };
    int ans = 2;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_2, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 1},
        {0, 0},
    };
    int ans = 1;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_3, content)
{
    std::vector<std::vector<int>> nnums = {
        {1, 0},
        {0, 0},
    };
    int ans = 0;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_4, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 0},
        {1, 0},
    };
    int ans = 1;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_5, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 0, 0},
        {1, 1 ,0},
        {0, 0, 0}
    };
    int ans = 1;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_6, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 0, 0},
        {1, 1 ,1},
        {0, 0, 0}
    };
    int ans = 0;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_7, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 1, 0},
        {1, 1 ,0},
        {0, 1, 0}
    };
    int ans = 0;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_8, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 0, 0},
        {1, 0 ,0},
        {0, 0, 0}
    };
    int ans = 3;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_9, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 0, 0},
        {1, 0 ,0},
        {1, 0, 0}
    };
    int ans = 3;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}

TEST(case_10, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 0, 0},
        {1, 0 ,0},
        {0, 1, 0}
    };
    int ans = 2;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}


TEST(case_11, content)
{
    std::vector<std::vector<int>> nnums = {
        {0, 0},
        {0, 1},
    };
    int ans = 0;
    EXPECT_EQ(uniquePathsWithObstacles(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstaclesDFS(nnums), ans);
    EXPECT_EQ(uniquePathsWithObstacles1(nnums), ans);
}