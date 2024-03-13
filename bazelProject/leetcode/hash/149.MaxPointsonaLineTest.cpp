#include "149.MaxPointsonaLine.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    int ans = 4;
    std::vector<vector<int>> vecNums =  {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    EXPECT_EQ(maxPoints(vecNums), ans);
    EXPECT_EQ(maxPoints1(vecNums), ans);
    EXPECT_EQ(maxPoints2(vecNums), ans);
    EXPECT_EQ(maxPoints3(vecNums), ans);
}

TEST(case_2,content)
{
    int ans = 2;
    std::vector<vector<int>> vecNums =  {{0,0},{1,0}};
    EXPECT_EQ(maxPoints(vecNums), ans);
    EXPECT_EQ(maxPoints1(vecNums), ans);
    EXPECT_EQ(maxPoints2(vecNums), ans);
    EXPECT_EQ(maxPoints3(vecNums), ans);
}

TEST(case_3,content)
{
    int ans = 1;
    std::vector<vector<int>> vecNums =  {{0,0}};
    EXPECT_EQ(maxPoints(vecNums), ans);
    EXPECT_EQ(maxPoints1(vecNums), ans);
    EXPECT_EQ(maxPoints2(vecNums), ans);
    EXPECT_EQ(maxPoints3(vecNums), ans);
}

TEST(case_4,content)
{
    int ans = 2;
    std::vector<vector<int>> vecNums =  {{1,0},{0,0}};
    EXPECT_EQ(maxPoints(vecNums), ans);
    EXPECT_EQ(maxPoints1(vecNums), ans);
    EXPECT_EQ(maxPoints2(vecNums), ans);
    EXPECT_EQ(maxPoints3(vecNums), ans);
}

TEST(case_5,content)
{
    int ans = 2;
    std::vector<vector<int>> vecNums =  {{0,0},{1,-1},{1,1}};
    EXPECT_EQ(maxPoints(vecNums), ans);
    EXPECT_EQ(maxPoints1(vecNums), ans);
    EXPECT_EQ(maxPoints2(vecNums), ans);
    EXPECT_EQ(maxPoints3(vecNums), ans);
}

TEST(case_6,content)
{
    int ans = 3;
    std::vector<vector<int>> vecNums =  {{2,3},{3,3},{-5,3}};
    EXPECT_EQ(maxPoints(vecNums), ans);
    EXPECT_EQ(maxPoints1(vecNums), ans);
    EXPECT_EQ(maxPoints2(vecNums), ans);
    EXPECT_EQ(maxPoints3(vecNums), ans);
}

TEST(case_7,content)
{
    int ans = 7;
    std::vector<vector<int>> vecNums =  {{0,1},{0,0},{0,4},{0,-2},{0,-1},{0,3},{0,-4}};
    EXPECT_EQ(maxPoints(vecNums), ans);
    EXPECT_EQ(maxPoints1(vecNums), ans);
    EXPECT_EQ(maxPoints2(vecNums), ans);
    EXPECT_EQ(maxPoints3(vecNums), ans);
}


TEST(case_8,content)
{
    int ans = 5;
    std::vector<vector<int>> vecNums =  {{0,0},{4,5},{7,8},{8,9},{5,6},{3,4},{1,1}};
    EXPECT_EQ(maxPoints(vecNums), ans);
    EXPECT_EQ(maxPoints1(vecNums), ans);
    EXPECT_EQ(maxPoints2(vecNums), ans);
    EXPECT_EQ(maxPoints3(vecNums), ans);
}