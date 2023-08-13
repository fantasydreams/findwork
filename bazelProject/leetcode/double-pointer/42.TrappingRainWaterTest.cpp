#include "42.TrappingRainWater.h"
#include "gtest/gtest.h"
#include <vector>

TEST(case_1, content)
{
    int ans = 6;
    std::vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    EXPECT_EQ(trap(vec), ans);
}


TEST(case_2, content)
{
    int ans = 9;
    std::vector<int> vec = {4,2,0,3,2,5};
    EXPECT_EQ(trap(vec), ans);
}