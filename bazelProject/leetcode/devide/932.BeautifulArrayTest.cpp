#include "932.BeautifulArray.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    int n = 1;
    std::vector<int> resVec = beautifulArray(n);
    std::vector<int> ans = {1};
    EXPECT_EQ(resVec, ans);
}

TEST(case_2,content)
{
    int n = 4;
    std::vector<int> resVec = beautifulArray(n);
    std::vector<int> ans = {1, 3, 2, 4};
    EXPECT_EQ(resVec, ans);
}

TEST(case_3,content)
{
    int n = 3;
    std::vector<int> resVec = beautifulArray(n);
    std::vector<int> ans = {1, 3, 2};
    EXPECT_EQ(resVec, ans);
}

TEST(case_4,content)
{
    int n = 5;
    std::vector<int> resVec = beautifulArray(n);
    std::vector<int> ans = {1, 5, 3, 2, 4};
    EXPECT_EQ(resVec, ans);
}