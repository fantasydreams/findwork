#include "461.HammingDistance.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    int x = 1, y = 3;
    int ans = 1;
    EXPECT_EQ(hammingDistance(x, y), ans);
    EXPECT_EQ(hammingDistance1(x, y), ans);
}

TEST(case_2,content)
{
    int x = 1, y = 1;
    int ans = 0;
    EXPECT_EQ(hammingDistance(x, y), ans);
    EXPECT_EQ(hammingDistance1(x, y), ans);
}


TEST(case_3,content)
{
    int x = 1, y = 4;
    int ans = 2;
    EXPECT_EQ(hammingDistance(x, y), ans);
    EXPECT_EQ(hammingDistance1(x, y), ans);
}