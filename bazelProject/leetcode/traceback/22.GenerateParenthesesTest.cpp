#include "22.GenerateParentheses.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    int n = 3;
    std::vector<std::string> vecAns = {"((()))","(()())","(())()","()(())","()()()"};
    EXPECT_EQ(generateParenthesis(n), vecAns);
}


TEST(case2, content) {
    int n = 1;
    std::vector<std::string> vecAns = {"()"};
    EXPECT_EQ(generateParenthesis(n), vecAns);
}