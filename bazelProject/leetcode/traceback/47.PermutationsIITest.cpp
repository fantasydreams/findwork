#include "47.PermutationsII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<int> nums = {1,1,1};
    vector<vector<int>> ans = {{1,1,1}};
    EXPECT_EQ(permuteUnique(nums), ans);
    EXPECT_EQ(permuteUnique1(nums), ans);
    EXPECT_EQ(permuteUnique2(nums), ans);
    EXPECT_EQ(permuteUnique3(nums), ans);
}

TEST(case_2,content)
{
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = {{1,1,2}, {1,2,1}, {2,1,1}};
    EXPECT_EQ(permuteUnique(nums), ans);
    EXPECT_EQ(permuteUnique1(nums), ans);
    EXPECT_EQ(permuteUnique2(nums), ans);
    EXPECT_EQ(permuteUnique3(nums), ans);
}

TEST(case_3,content)
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, { 2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 } };
    EXPECT_EQ(permuteUnique(nums), ans);
    EXPECT_EQ(permuteUnique1(nums), ans);
    EXPECT_EQ(permuteUnique2(nums), ans);
    EXPECT_EQ(permuteUnique3(nums), ans);
}
