#include "94.BinaryTreeInorderTraversal.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {2, 1, 4, 3};
    std::vector<int> mid = {1, 2, 3, 4};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<int> traverse = inorderTraversal(root);
    std::vector<int> vec1 = inorderTraversal1(root);
    EXPECT_EQ(vec1, mid);
    EXPECT_EQ(traverse, mid);
    FreeTree(root);
}

TEST(case_2, content)
{
    std::vector<int> pre = {1, 2, 3};
    std::vector<int> mid = {1, 3, 2};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<int> traverse = inorderTraversal(root);

    std::vector<int> vec1 = inorderTraversal1(root);
    EXPECT_EQ(vec1, mid);
    EXPECT_EQ(traverse, mid);
    FreeTree(root);
}