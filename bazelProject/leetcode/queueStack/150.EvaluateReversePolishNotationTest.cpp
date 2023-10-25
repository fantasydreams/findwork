#include "150.EvaluateReversePolishNotation.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<std::string> tokens = {"2","1","+","3","*"};
    int ans = 9;
    EXPECT_EQ(evalRPN(tokens), ans);
}


TEST(case_2, content) {
    std::vector<std::string> tokens = {"4","13","5","/","+"};
    int ans = 6;
    EXPECT_EQ(evalRPN(tokens), ans);
}

TEST(case_3, content) {
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int ans = 22;
    EXPECT_EQ(evalRPN(tokens), ans);
}