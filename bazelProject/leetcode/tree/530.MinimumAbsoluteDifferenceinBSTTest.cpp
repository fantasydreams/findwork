#include "530.MinimumAbsoluteDifferenceinBST.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> pre = {4, 2, 1, 3, 6};
    std::vector<int> mid = {1, 2, 3, 4, 6};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 1;
    EXPECT_EQ(getMinimumDifference(root), ans);
    EXPECT_EQ(getMinimumDifference1(root), ans);
    FreeTree(root);
}

TEST(case_2,content)
{
    std::vector<int> pre = {1, 0, 48, 12, 49};
    std::vector<int> mid = {0, 1, 12, 48, 49};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 1;
    EXPECT_EQ(getMinimumDifference(root), ans);
    EXPECT_EQ(getMinimumDifference1(root), ans);
    FreeTree(root);
}