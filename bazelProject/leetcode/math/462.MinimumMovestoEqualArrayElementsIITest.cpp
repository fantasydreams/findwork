#include "462.MinimumMovestoEqualArrayElementsII.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> nums = {1,2,3};
    int ans = 2;
    EXPECT_EQ(minMoves2(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {1,10,2,9};
    int ans = 16;
    EXPECT_EQ(minMoves2(nums), ans);
}