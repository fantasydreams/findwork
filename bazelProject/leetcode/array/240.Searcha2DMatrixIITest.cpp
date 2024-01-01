#include "240.Searcha2DMatrixII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    bool ans = true;
    EXPECT_EQ(searchMatrix(matrix, target), ans);
    EXPECT_EQ(searchMatrix_2(matrix, target), ans);
}


TEST(case_2,content)
{
    std::vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 20;
    bool ans = false;
    EXPECT_EQ(searchMatrix(matrix, target), ans);
    EXPECT_EQ(searchMatrix_2(matrix, target), ans);
}

TEST(case_3,content)
{
    std::vector<vector<int>> matrix = {{-1,3}};
    int target = 3;
    bool ans = true;
    EXPECT_EQ(searchMatrix(matrix, target), ans);
    EXPECT_EQ(searchMatrix_2(matrix, target), ans);
}

TEST(case_4, content)
{
    std::vector<vector<int>> matrix = {{-5}};
    int target = -2;
    bool ans = false;
    EXPECT_EQ(searchMatrix(matrix, target), ans);
    EXPECT_EQ(searchMatrix_2(matrix, target), ans);
}

TEST(case_5, content)
{
    std::vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int target = 25;
    bool ans = true;
    EXPECT_EQ(searchMatrix(matrix, target), ans);
    EXPECT_EQ(searchMatrix_2(matrix, target), ans);
}
