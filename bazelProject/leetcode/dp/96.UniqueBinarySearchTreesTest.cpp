#include "96.UniqueBinarySearchTrees.h"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>


// 测试RR
TEST(case_1, content)
{
    int n = 0;
    int ans = 1;
    EXPECT_EQ(numTrees(n), ans);
}

TEST(case_2, content)
{
    int n = 1;
    int ans = 1;
    EXPECT_EQ(numTrees(n), ans);
}


TEST(case_3, content)
{
    int n = 3;
    int ans = 5;
    EXPECT_EQ(numTrees(n), ans);
}