#include "110.BalancedBinaryTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = true;
    EXPECT_EQ(isBalanced(root), ans);
    EXPECT_EQ(isBalanced1(root), ans);
    FreeTree(root);
}

TEST(case_2, content)
{
    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> mid = {9, 3, 15, 20, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = true;
    EXPECT_EQ(isBalanced(root), ans);
    EXPECT_EQ(isBalanced1(root), ans);
    FreeTree(root);
}

TEST(case_3, content)
{
    std::vector<int> pre = {1, 2, 3, 4, 4, 3, 2};
    std::vector<int> mid = {4, 3, 4, 2, 3, 1, 2};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = false;
    EXPECT_EQ(isBalanced(root), ans);
    EXPECT_EQ(isBalanced1(root), ans);
    FreeTree(root);
}