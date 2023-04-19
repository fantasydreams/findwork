#include "662.MaximumWidthofBinaryTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int width = 4;
    EXPECT_EQ(widthOfBinaryTree(root), width);
    FreeTree(root);
}

TEST(case_2, content)
{
    std::vector<int> pre = {1, 3, 5, 4, 2, 9};
    std::vector<int> mid = {5, 3, 4, 1, 2, 9};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int width = 4;
    EXPECT_EQ(widthOfBinaryTree(root), width);
    EXPECT_EQ(widthOfBinaryTree1(root), width);
    FreeTree(root);
}

TEST(case_3, content)
{
    std::vector<int> pre = {1, 3, 5, 6, 2, 9, 7};
    std::vector<int> mid = {6, 5, 3, 1, 2, 7, 9};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int width = 7;
    EXPECT_EQ(widthOfBinaryTree(root), width);
    EXPECT_EQ(widthOfBinaryTree1(root), width);
    FreeTree(root);
}

TEST(case_4, content)
{
    std::vector<int> pre = {1, 3, 5, 2};
    std::vector<int> mid = {5, 3, 1, 2};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int width = 2;
    EXPECT_EQ(widthOfBinaryTree(root), width);
    EXPECT_EQ(widthOfBinaryTree1(root), width);
    FreeTree(root);
}

TEST(case_5, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 8, 9, 11, 15, 12, 16, 10, 13, 17, 14, 18, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 15, 11, 16, 12, 9, 8, 13, 17, 10, 14, 18, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int width = 8;
    EXPECT_EQ(widthOfBinaryTree(root), width);
    EXPECT_EQ(widthOfBinaryTree1(root), width);
    FreeTree(root);
}