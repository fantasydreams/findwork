#include "85.MaximalRectangle.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<std::vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int ans = 6;
    EXPECT_EQ(maximalRectangle(matrix), ans);
}

TEST(case_2,content)
{
    std::vector<std::vector<char>> matrix = {{'0'}};
    int ans = 0;
    EXPECT_EQ(maximalRectangle(matrix), ans);
}

TEST(case_3,content)
{
    std::vector<std::vector<char>> matrix = {{'1'}};
    int ans = 1;
    EXPECT_EQ(maximalRectangle(matrix), ans);
}