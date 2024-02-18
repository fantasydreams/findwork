#include "909.SnakesandLadders.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    std::vector<std::vector<int>> board = {{-1,-1,-1,-1,-1,-1},
                                            {-1,-1,-1,-1,-1,-1},
                                            {-1,-1,-1,-1,-1,-1},
                                            {-1,35,-1,-1,13,-1},
                                            {-1,-1,-1,-1,-1,-1},
                                            {-1,15,-1,-1,-1,-1}};
    int ans = 4;
    EXPECT_EQ(snakesAndLadders(board), ans);
}


TEST(case2, content) {
    std::vector<std::vector<int>> board = {{-1,-1},
                                            {-1,3}};
    int ans = 1;
    EXPECT_EQ(snakesAndLadders(board), ans);
}


TEST(case3, content) {
    std::vector<std::vector<int>> board = {{-1,-1,19,10,-1},
                                            {2,-1,-1,6,-1},
                                            {-1,17,-1,19,-1},
                                            {25,-1,20,-1,-1},
                                            {-1,-1,-1,-1,15}};
    int ans = 2;
    EXPECT_EQ(snakesAndLadders(board), ans);
}