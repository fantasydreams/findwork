#include "200.NumberofIslands.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<std::vector<char>> matrix = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int ans = 1;
    EXPECT_EQ(numIslands(matrix), ans);
    EXPECT_EQ(numIslands1(matrix), ans);
}


TEST(case_2, content) {
    std::vector<std::vector<char>> matrix = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    int ans = 3;
    EXPECT_EQ(numIslands(matrix), ans);
    EXPECT_EQ(numIslands1(matrix), ans);
}