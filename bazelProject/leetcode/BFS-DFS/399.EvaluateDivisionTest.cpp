#include "399.EvaluateDivision.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    std::vector<std::vector<string>> equations = {{"a","b"},{"b","c"}}, queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    std::vector<double> ans = {6.00000,0.50000,-1.00000,1.00000,-1.00000}, values = {2.0,3.0};
    EXPECT_EQ(calcEquation(equations, values, queries), ans);
}


TEST(case2, content) {
    std::vector<std::vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}}, queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    std::vector<double> ans = {3.75000,0.40000,5.00000,0.20000}, values = {1.5,2.5,5.0};
    EXPECT_EQ(calcEquation(equations, values, queries), ans);
}


TEST(case3, content) {
    std::vector<std::vector<string>>  equations= {{"a","b"}}, queries = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
    std::vector<double> ans = {0.50000,2.00000,-1.00000,-1.00000}, values = {0.5};
    EXPECT_EQ(calcEquation(equations, values, queries), ans);
}