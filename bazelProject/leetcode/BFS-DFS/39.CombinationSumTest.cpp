#include "39.CombinationSum.h"
#include "gtest/gtest.h"
#include <vector>

TEST(case_1, content)
{
    int target = 7;
    std::vector<int> candidates = {2,3,6,7};
    std::vector<std::vector<int> > ans = {{2,2,3},{7}};
    EXPECT_EQ(combinationSum(candidates, target), ans);
    EXPECT_EQ(combinationSum1(candidates, target), ans);
}


TEST(case_2, content)
{
    int target = 8;
    std::vector<int> candidates = {2,3,5};
    std::vector<std::vector<int> > ans = {{2,2,2,2},{2, 3, 3}, {3, 5}};
    EXPECT_EQ(combinationSum(candidates, target), ans);
    EXPECT_EQ(combinationSum1(candidates, target), ans);
}

TEST(case_3, content)
{
    int target = 1;
    std::vector<int> candidates = {2};
    std::vector<std::vector<int> > ans = {};
    EXPECT_EQ(combinationSum(candidates, target), ans);
    EXPECT_EQ(combinationSum1(candidates, target), ans);
}