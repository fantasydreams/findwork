#include "224.BasicCalculator.h"
#include "gtest/gtest.h"

TEST(BasicCalculator1, function1) {
    std::string s = "1 + 1";
    int ans = 2;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}


TEST(BasicCalculator2, function2) {
    std::string s = " 2-1 + 2 ";
    int ans = 3;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}

TEST(BasicCalculator3, function3) {
    std::string s = "(1+(4+5+2)-3)+(6+8)";
    int ans = 23;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}

TEST(BasicCalculator4, function3) {
    std::string s = "";
    int ans = 0;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}



TEST(BasicCalculator5, function3) {
    std::string s = "  ";
    int ans = 0;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}


TEST(BasicCalculator6, function3) {
    std::string s = " (1-(4-5+2)-3)+(6-8) ";
    int ans = -5;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}


TEST(BasicCalculator7, function3) {
    std::string s = " -2+ 1 ";
    int ans = -1;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}

TEST(BasicCalculator8, function3) {
    std::string s = " +2";
    int ans = 2;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}

TEST(BasicCalculator9, function3) {
    std::string s = "-2+ (-1)";
    int ans = -3;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}


TEST(BasicCalculator10, function3) {
    std::string s = "- (3 + (4 + 5))";
    int ans = -12;

    EXPECT_EQ(calculate(s), ans);
    EXPECT_EQ(calculate1(s), ans);
}