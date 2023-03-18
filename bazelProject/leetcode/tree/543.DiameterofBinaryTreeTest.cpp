#include "543.DiameterofBinaryTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 4;
    EXPECT_EQ(diameterOfBinaryTree(root), ans);
    FreeTree(root);
}

TEST(case_2, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3};
    std::vector<int> mid = {4, 2, 5, 1, 3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 3;
    EXPECT_EQ(diameterOfBinaryTree(root), ans);
    FreeTree(root);
}

TEST(case_3, content)
{
    std::vector<int> pre = {1,2};
    std::vector<int> mid = {2,1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 1;
    EXPECT_EQ(diameterOfBinaryTree(root), ans);
    FreeTree(root);
}