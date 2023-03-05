#include "338.CountingBits.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    std::vector<int> ans = {0, 1, 1};
    int num = 2;
    EXPECT_EQ(countBits(num), ans);
}


TEST(case_2,content)
{
    std::vector<int> ans = {0,1,1,2,1,2};
    int num = 5;
    EXPECT_EQ(countBits(num), ans);
}