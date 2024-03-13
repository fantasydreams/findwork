#include "502.IPO.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    int k = 2, w = 0, ans = 4;
    std::vector<int> profits = {1,2,3}, capital = {0,1,1};
    EXPECT_EQ(findMaximizedCapital(k, w, profits, capital), ans);
}


TEST(case2, content) {
    int k = 3, w = 0, ans = 6;
    std::vector<int> profits = {1,2,3}, capital = {0,1,2};
    EXPECT_EQ(findMaximizedCapital(k, w, profits, capital), ans);
}