#include "64.MinimumPathSum.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<std::vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int ans = 7;
    EXPECT_EQ(minPathSum(grid), ans);
    EXPECT_EQ(minPathSum1(grid), ans);
    EXPECT_EQ(minPathSum2(grid), ans);
    EXPECT_EQ(minPathSumDp(grid), ans);
    EXPECT_EQ(minPathSumDpCompress(grid), ans);
}

TEST(case_2,content)
{
    std::vector<std::vector<int>> grid = {{1,2,3},{4,5,6}};
    int ans = 12;
    EXPECT_EQ(minPathSum(grid), ans);
    EXPECT_EQ(minPathSum1(grid), ans);
    EXPECT_EQ(minPathSum2(grid), ans);
    EXPECT_EQ(minPathSumDp(grid), ans);
    EXPECT_EQ(minPathSumDpCompress(grid), ans);
}