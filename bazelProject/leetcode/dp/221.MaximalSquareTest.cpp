#include "221.MaximalSquare.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<std::vector<char>> nums = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int ans = 4;
    EXPECT_EQ(maximalSquare(nums), ans);
}

TEST(case_2,content)
{
    std::vector<std::vector<char>> nums = {{'0','1'},{'1','0'}};
    int ans = 1;
    EXPECT_EQ(maximalSquare(nums), ans);
}

TEST(case_3,content)
{
    std::vector<std::vector<char>> nums = {{'0'}};
    int ans = 0;
    EXPECT_EQ(maximalSquare(nums), ans);
}