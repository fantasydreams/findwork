#include "74.Searcha2DMatrix.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include "gtest/gtest.h"


TEST(case_1, content)
{
    std::vector<std::vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60},
    };
    int target = 3;
    EXPECT_EQ(searchMatrix(matrix, target), true);
}

TEST(case_2, content)
{
    std::vector<std::vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60},
    };
    int target = 9;
    EXPECT_EQ(searchMatrix(matrix, target), false);
}

TEST(case_3, content)
{
    std::vector<std::vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60},
    };
    int target = 61;
    EXPECT_EQ(searchMatrix(matrix, target), false);
}