#include "73.SetMatrixZeroes.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    std::vector<std::vector<int>> ans = {{1,0,1},{0,0,0},{1,0,1}};
    setZeroes(matrix);
    for(int i = 0; i < ans.size(); ++i) {
        EXPECT_EQ(matrix[i], ans[i]);
    }
}

TEST(case_2,content)
{
    std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    std::vector<std::vector<int>> ans = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    setZeroes(matrix);
    for(int i = 0; i < ans.size(); ++i) {
        EXPECT_EQ(matrix[i], ans[i]);
    }
}

TEST(case_3,content)
{
    std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    std::vector<std::vector<int>> ans = {{1,0,1},{0,0,0},{1,0,1}};
    setZeroes1(matrix);
    for(int i = 0; i < ans.size(); ++i) {
        EXPECT_EQ(matrix[i], ans[i]);
    }
}

TEST(case_4,content)
{
    std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    std::vector<std::vector<int>> ans = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    setZeroes1(matrix);
    for(int i = 0; i < ans.size(); ++i) {
        EXPECT_EQ(matrix[i], ans[i]);
    }
}