#include "233.NumberofDigitOne.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int n = 0;
    int ans = 0;
    EXPECT_EQ(countDigitOne(n), ans);
}


TEST(case_2, content) {
    int n = 1;
    int ans = 1;
    EXPECT_EQ(countDigitOne(n), ans);
}

TEST(case_3, content) {
    int n = 10;
    int ans = 2;
    EXPECT_EQ(countDigitOne(n), ans);
}


TEST(case_4, content) {
    int n = 13;
    int ans = 6;
    EXPECT_EQ(countDigitOne(n), ans);
}