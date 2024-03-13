#include "201.BitwiseANDofNumbersRange.h"
#include "gtest/gtest.h"
#include <stdlib.h>

TEST(case_1, content) {
    int left = 5, right = 7;
    int ans = 4;
    EXPECT_EQ(rangeBitwiseAnd(left, right) ,ans);
    EXPECT_EQ(rangeBitwiseAndMath(left, right) ,ans);
    EXPECT_EQ(rangeBitwiseAnd1(left, right) ,ans);
}


TEST(case_2, content) {
    int left = 1, right = INT_MAX;
    int ans = 0;
    EXPECT_EQ(rangeBitwiseAnd(left, right) ,ans);
    EXPECT_EQ(rangeBitwiseAndMath(left, right) ,ans);
    EXPECT_EQ(rangeBitwiseAnd1(left, right) ,ans);
}


TEST(case_3, content) {
    int left = 0, right = 0;
    int ans = 0;
    EXPECT_EQ(rangeBitwiseAnd(left, right) ,ans);
    EXPECT_EQ(rangeBitwiseAndMath(left, right) ,ans);
    EXPECT_EQ(rangeBitwiseAnd1(left, right) ,ans);
}


TEST(case_4, content) {
    int left = 1, right = 2;
    int ans = 0;
    EXPECT_EQ(rangeBitwiseAnd(left, right) ,ans);
    EXPECT_EQ(rangeBitwiseAndMath(left, right) ,ans);
    EXPECT_EQ(rangeBitwiseAnd1(left, right) ,ans);
}