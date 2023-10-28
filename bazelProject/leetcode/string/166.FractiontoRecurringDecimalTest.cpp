#include "166.FractiontoRecurringDecimal.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(case_1, content) {
    std::string ans = "0.(3)";
    int num = 1, denum = 3;
    EXPECT_EQ(fractionToDecimal(num, denum), ans);
}


TEST(case_2, content) {
    std::string ans = "2";
    int num = 2, denum = 1;
    EXPECT_EQ(fractionToDecimal(num, denum), ans);
}

TEST(case_3, content) {
    std::string ans = "0.(012)";
    int num = 4, denum = 333;
    EXPECT_EQ(fractionToDecimal(num, denum), ans);
}


TEST(case_4, content) {
    std::string ans = "0.25";
    int num = 1, denum = 4;
    EXPECT_EQ(fractionToDecimal(num, denum), ans);
}


TEST(case_5, content) {
    std::string ans = "0.0000000004656612873077392578125";
    int num = -1, denum = -2147483648;
    EXPECT_EQ(fractionToDecimal(num, denum), ans);
}

TEST(case_6, content) {
    std::string ans = "2147483648";
    int num = -2147483648, denum = -1;
    EXPECT_EQ(fractionToDecimal(num, denum), ans);
}