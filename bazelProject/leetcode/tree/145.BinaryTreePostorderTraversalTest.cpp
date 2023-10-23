#include "145.BinaryTreePostorderTraversal.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    std::vector<int> post = {4, 5, 2, 6, 7, 3, 1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<int> traverse = postorderTraversal(root);
    EXPECT_EQ(traverse, post);
    FreeTree(root);
}


TEST(case_2, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    std::vector<int> post = {4, 5, 2, 6, 7, 3, 1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<int> traverse = postorderTraversal1(root);
    EXPECT_EQ(traverse, post);
    FreeTree(root);
}