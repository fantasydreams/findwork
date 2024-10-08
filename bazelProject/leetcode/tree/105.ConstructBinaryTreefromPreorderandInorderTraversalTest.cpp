#include "105.ConstructBinaryTreefromPreorderandInorderTraversal.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    TreeNode * newRoot = buildTree(pre, mid);
    TraverseTreePreNoRecursion(root);
    // printf("\n");
    TraverseTreePreNoRecursion(newRoot);
    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_2, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    TreeNode * newRoot = buildTree1(pre, mid);
    TraverseTreePreNoRecursion(root);
    // printf("\n");
    TraverseTreePreNoRecursion(newRoot);
    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_3, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    TreeNode * newRoot = buildTreeHash(pre, mid);
    TraverseTreePreNoRecursion(root);
    // printf("\n");
    TraverseTreePreNoRecursion(newRoot);
    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_4, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    TreeNode * newRoot = buildTreeHash1(pre, mid);
    TraverseTreePreNoRecursion(root);
    // printf("\n");
    TraverseTreePreNoRecursion(newRoot);
    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}