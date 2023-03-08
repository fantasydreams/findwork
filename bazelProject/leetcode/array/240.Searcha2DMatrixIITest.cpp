#include "240.Searcha2DMatrixII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    bool ans = true;
    EXPECT_EQ(searchMatrix(matrix, target), ans);
}


TEST(case_2,content)
{
    std::vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 20;
    bool ans = false;
    EXPECT_EQ(searchMatrix(matrix, target), ans);
}

TEST(case_3,content)
{
    std::vector<vector<int>> matrix = {{-1,3}};
    int target = 3;
    bool ans = true;
    EXPECT_EQ(searchMatrix(matrix, target), ans);
}
