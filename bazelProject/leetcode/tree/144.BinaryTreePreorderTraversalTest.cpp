#include "144.BinaryTreePreorderTraversal.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<int> traverse = preorderTraversal(root);
    TraverseTreePreNoRecursion(root);
    EXPECT_EQ(traverse, pre);
    FreeTree(root);
}