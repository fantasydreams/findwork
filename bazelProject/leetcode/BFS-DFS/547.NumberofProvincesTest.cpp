#include "547.NumberofProvinces.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    EXPECT_EQ(findCircleNum(isConnected), 2);
    EXPECT_EQ(findCircleNum1(isConnected), 2);
}

TEST(case_2,content)
{
    vector<vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    EXPECT_EQ(findCircleNum(isConnected), 3);
    EXPECT_EQ(findCircleNum1(isConnected), 3);
}

TEST(case_3,content)
{
    vector<vector<int>> isConnected = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    EXPECT_EQ(findCircleNum(isConnected), 1);
    EXPECT_EQ(findCircleNum1(isConnected), 1);
}
