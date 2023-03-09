#include "218.TheSkylineProblem.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    vector<vector<int>> Input = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> Output = {{2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0}};

    EXPECT_EQ(getSkyline(Input), Output);
    EXPECT_EQ(getSkyline1(Input), Output);
}


TEST(case_2,content)
{
    vector<vector<int>> Input = {{0,2,3},{2,5,3}};
    vector<vector<int>> Output = {{0,3},{5,0}};

    EXPECT_EQ(getSkyline(Input), Output);
    EXPECT_EQ(getSkyline1(Input), Output);
}