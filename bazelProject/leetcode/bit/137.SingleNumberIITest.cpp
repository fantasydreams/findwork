#include "137.SingleNumberII.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> vec = {2,2,3,2};
    int ans = 3;
    EXPECT_EQ(singleNumberHash(vec), ans);
    EXPECT_EQ(singleNumberBit(vec), ans);
    EXPECT_EQ(singleNumberBit1(vec), ans);
    EXPECT_EQ(singleNumberBit2(vec), ans);
}


TEST(case_2, content) {
    std::vector<int> vec = {0,1,0,1,0,1,99};
    int ans = 99;
    EXPECT_EQ(singleNumberHash(vec), ans);
    EXPECT_EQ(singleNumberBit(vec), ans);
    EXPECT_EQ(singleNumberBit1(vec), ans);
    EXPECT_EQ(singleNumberBit2(vec), ans);
}