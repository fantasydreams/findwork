#include "56.MergeIntervals.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}}, ans = {{1,6},{8,10},{15,18}};
    EXPECT_EQ(merge(intervals), ans);
}


TEST(case_2,content)
{
    vector<vector<int>> intervals = {{1,4},{4,5}}, ans = {{1,5}};
    EXPECT_EQ(merge(intervals), ans);
}


TEST(case_3,content)
{
    vector<vector<int>> intervals = {{1,4}, {2,3}}, ans = {{1,4}};
    EXPECT_EQ(merge(intervals), ans);
}


TEST(case_11,content)
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}}, ans = {{1,6},{8,10},{15,18}};
    EXPECT_EQ(merge1(intervals), ans);
}


TEST(case_21,content)
{
    vector<vector<int>> intervals = {{1,4},{4,5}}, ans = {{1,5}};
    EXPECT_EQ(merge1(intervals), ans);
}


TEST(case_23,content)
{
    vector<vector<int>> intervals = {{1,4}, {2,3}}, ans = {{1,4}};
    EXPECT_EQ(merge1(intervals), ans);
}