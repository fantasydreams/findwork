#include "gtest/gtest.h"
#include <vector>
#include "89.GrayCode.h"


TEST(case_1,content)
{
    int n = 0;
    std::vector<int> ans = {0};
    EXPECT_EQ(grayCode(n), ans);
    EXPECT_EQ(grayCode1(n), ans);
}


TEST(case_2, content)
{
    int n = 1;
    std::vector<int> ans = {0, 1};
    EXPECT_EQ(grayCode(n), ans);
    EXPECT_EQ(grayCode1(n), ans);
}


TEST(case_3, content)
{
    int n = 2;
    std::vector<int> ans = {0, 1, 3, 2};
    EXPECT_EQ(grayCode(n), ans);
    EXPECT_EQ(grayCode1(n), ans);
}