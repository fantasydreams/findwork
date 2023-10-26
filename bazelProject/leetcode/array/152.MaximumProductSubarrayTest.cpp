#include "152.MaximumProductSubarray.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> vec = {2,3,-2,4};
    int ans = 6;
    EXPECT_EQ(maxProduct(vec), ans);
}


TEST(case_2, content) {
    std::vector<int> vec = {-2,0,-1};
    int ans = 0;
    EXPECT_EQ(maxProduct(vec), ans);
}