#include "513.FindBottomLeftTreeValue.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 4;
    EXPECT_EQ(findBottomLeftValue(root), ans);
    FreeTree(root);
}

TEST(case_2,content)
{
    std::vector<int> pre = {2, 1, 3};
    std::vector<int> mid = {1, 2, 3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 1;
    EXPECT_EQ(findBottomLeftValue(root), ans);
    FreeTree(root);
}

TEST(case_3,content)
{
    std::vector<int> pre = {1, 2, 4, 3, 5, 7, 6};
    std::vector<int> mid = {4, 2, 1, 7, 5, 3, 6};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 7;
    EXPECT_EQ(findBottomLeftValue(root), ans);
    FreeTree(root);
}