#include "57.InsertInterval.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    vector<vector<int>> intervals = {}, ans = {{2,3}};
    vector<int> in = {2,3};
    // EXPECT_EQ(insert(intervals, in), ans);

    intervals = {};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_2,content)
{
    vector<vector<int>> intervals = {{3, 4}}, ans = {{1,2}, {3,4}};
    vector<int> in = {1,2};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{3, 4}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_3,content)
{
    vector<vector<int>> intervals = {{1,3},{4,6}}, ans = {{0,3}, {4,6}};
    vector<int> in = {0,1};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1,3},{4,6}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_4,content)
{
    vector<vector<int>> intervals = {{1,3},{4,6}}, ans = {{0,3}, {4,6}};
    vector<int> in = {0,2};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1,3},{4,6}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_5,content)
{
    vector<vector<int>> intervals = {{1,3},{4,6}}, ans = {{0,3}, {4,6}};
    vector<int> in = {0,3};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1,3},{4,6}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_6,content)
{
    vector<vector<int>> intervals = {{1,3}, {4,6}}, ans = {{0,3}, {4,6}};
    vector<int> in = {0, 3};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1,3}, {4,6}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_7, content)
{
    vector<vector<int>> intervals = {{1, 4}, {5, 6}}, ans = {{1, 4}, {5, 6}};
    vector<int> in = {2, 3};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1, 4}, {5, 6}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_8, content)
{
    vector<vector<int>> intervals = {{1, 4}, {5, 6}}, ans = {{1, 6}};
    vector<int> in = {2, 5};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1, 4}, {5, 6}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_9, content)
{
    vector<vector<int>> intervals = {{1, 4}, {5, 6}, {8, 9}}, ans = {{1, 6}, {8, 9}};
    vector<int> in = {2, 5};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1, 4}, {5, 6}, {8, 9}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_10, content)
{
    vector<vector<int>> intervals = {{1, 4}, {5, 6}, {8, 9}}, ans = {{1, 10}};
    vector<int> in = {2, 10};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1, 4}, {5, 6}, {8, 9}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_11, content)
{
    vector<vector<int>> intervals = {{1, 4}, {5, 6}, {8, 9}}, ans = {{0, 10}};
    vector<int> in = {0, 10};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1, 4}, {5, 6}, {8, 9}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_12, content)
{
    vector<vector<int>> intervals = {{1, 4}}, ans = {{1, 4}, {5, 6}};
    vector<int> in = {5, 6};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{1, 4}};
    EXPECT_EQ(insert1(intervals, in), ans);
}

TEST(case_13, content)
{
    vector<vector<int>> intervals = {{3, 5}, {15, 18}}, ans = {{3, 5}, {6, 9}, {15, 18}};
    vector<int> in = {6, 9};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{3, 5}, {15, 18}};
    EXPECT_EQ(insert1(intervals, in), ans);
}


TEST(case_14, content)
{
    vector<vector<int>> intervals = {{3,6}, {9,9}, {11,13},{14,14},{16,19},{20,22},{23,25},{30,34},{41,43},{45,49}}, ans = {{3,6},{9,9},{11,13},{14,14},{16,19},{20,22},{23,25},{29,34},{41,43},{45,49}};
    vector<int> in = {29, 32};
    EXPECT_EQ(insert(intervals, in), ans);

    intervals = {{3,6}, {9,9}, {11,13},{14,14},{16,19},{20,22},{23,25},{30,34},{41,43},{45,49}};
    EXPECT_EQ(insert1(intervals, in), ans);
}