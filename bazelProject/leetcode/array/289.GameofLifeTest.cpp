#include "289.GameofLife.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    vector<vector<int>> ans = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
    gameOfLife(board);
    ASSERT_EQ(ans, board);
}


TEST(case_2, content) {
    vector<vector<int>> board = {{1,1},{1,0}};
    vector<vector<int>> ans = {{1,1},{1,1}};
    gameOfLife(board);
    ASSERT_EQ(ans, board);
}


TEST(case_3, content) {
    vector<vector<int>> board = {{1},{0},{0},{1},{0},{0},{1},{0},{0},{1}};
    vector<vector<int>> ans = {{1},{0},{0},{1},{0},{0},{1},{0},{0},{1}};;
    gameOfLife(board);
    ASSERT_EQ(ans, board);
}