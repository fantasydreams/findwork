#include "566.ReshapetheMatrix.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<vector<int>> nums = {{1,2},{3,4}};
    std::vector<vector<int>> ans = {{1,2,3,4}};
    int  r = 1, c = 4;
    EXPECT_EQ(matrixReshape(nums, r, c), ans);
}

TEST(case_2,content)
{
    std::vector<vector<int>> nums = {{1,2},{3,4}};
    std::vector<vector<int>> ans = {{1,2},{3,4}};
    int  r = 2, c = 4;
    EXPECT_EQ(matrixReshape(nums, r, c), ans);
}

TEST(case_3,content)
{
    std::vector<vector<int>> nums = {{1,2,3,4}};
    std::vector<vector<int>> ans = {{1,2},{3,4}};
    int  r = 2, c = 2;
    EXPECT_EQ(matrixReshape(nums, r, c), ans);
}