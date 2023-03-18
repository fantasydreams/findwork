#include "404.SumofLeftLeaves.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 10;
    EXPECT_EQ(sumOfLeftLeaves(root), ans);
    FreeTree(root);
}

TEST(case_2,content)
{
    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> mid = {9, 3, 15, 20, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 24;
    EXPECT_EQ(sumOfLeftLeaves(root), ans);
    FreeTree(root);
}