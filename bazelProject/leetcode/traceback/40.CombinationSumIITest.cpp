#include "40.CombinationSumII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    std::vector<std::vector<int>> ans = {{1,1,6},{1,2,5},{1,7},{2,6}};
    EXPECT_EQ(combinationSum2(candidates, target), ans);
    EXPECT_EQ(combinationSum2_(candidates, target), ans);
}

TEST(case_2,content)
{
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    std::vector<std::vector<int>> ans = {{1,2,2},{5}};
    EXPECT_EQ(combinationSum2(candidates, target), ans);
    EXPECT_EQ(combinationSum2_(candidates, target), ans);
}

TEST(case_3,content)
{
    vector<int> candidates = {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    int target = 27;
    std::vector<std::vector<int>> ans = { { 6, 6, 7, 8 }, { 6, 7, 14 }, { 6, 8, 13 }, { 6, 9, 12 }, { 6, 10, 11 }, { 6, 21 }, { 7, 8, 12 }, { 7, 9, 11 }, { 7, 20 }, { 8, 8, 11 }, { 8, 9, 10 }, { 9, 9, 9 }, { 9, 18 }, { 10, 17 }, { 11, 16 }, { 13, 14 }, { 27 } };
    EXPECT_EQ(combinationSum2(candidates, target), ans);
    EXPECT_EQ(combinationSum2_(candidates, target), ans);
}