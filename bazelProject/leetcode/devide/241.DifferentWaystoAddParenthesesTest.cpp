#include "241.DifferentWaystoAddParentheses.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    std::vector<int> ans = {0, 2};
    std::string expression = "2-1-1";
    std::vector<int> resVec = diffWaysToCompute(expression);
    std::vector<int> resVec1 = diffWaysToCompute1(expression);
    std::vector<int> resVec2 = diffWaysToCompute2(expression);
    std::sort(resVec.begin(),resVec.end());
    std::sort(resVec1.begin(),resVec1.end());
    std::sort(resVec2.begin(),resVec2.end());
    EXPECT_EQ(resVec, ans);
    EXPECT_EQ(resVec1, ans);
    EXPECT_EQ(resVec2, ans);
}


TEST(case_2,content)
{
    std::vector<int> ans = {2};
    std::string expression = "2";
    std::vector<int> resVec = diffWaysToCompute(expression);
    std::vector<int> resVec1 = diffWaysToCompute1(expression);
    std::vector<int> resVec2 = diffWaysToCompute2(expression);
    std::sort(resVec.begin(),resVec.end());
    std::sort(resVec1.begin(),resVec1.end());
    std::sort(resVec2.begin(),resVec2.end());
    EXPECT_EQ(resVec, ans);
    EXPECT_EQ(resVec1, ans);
    EXPECT_EQ(resVec2, ans);
}

TEST(case_3,content)
{
    std::vector<int> ans = {1};
    std::string expression = "2-1";
    std::vector<int> resVec = diffWaysToCompute(expression);
    std::vector<int> resVec1 = diffWaysToCompute1(expression);
    std::vector<int> resVec2 = diffWaysToCompute2(expression);
    std::sort(resVec.begin(),resVec.end());
    std::sort(resVec1.begin(),resVec1.end());
    std::sort(resVec2.begin(),resVec2.end());
    EXPECT_EQ(resVec, ans);
    EXPECT_EQ(resVec1, ans);
    EXPECT_EQ(resVec2, ans);
}

TEST(case_4,content)
{
    std::vector<int> ans = {-34,-14,-10,-10,10};
    std::string expression = "2*3-4*5";
    std::vector<int> resVec = diffWaysToCompute(expression);
    std::vector<int> resVec1 = diffWaysToCompute1(expression);
    std::vector<int> resVec2 = diffWaysToCompute2(expression);
    std::sort(resVec.begin(),resVec.end());
    std::sort(resVec1.begin(),resVec1.end());
    std::sort(resVec2.begin(),resVec2.end());
    EXPECT_EQ(resVec, ans);
    EXPECT_EQ(resVec1, ans);
    EXPECT_EQ(resVec2, ans);
}
