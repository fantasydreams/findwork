#include "99.RecoverBinarySearchTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {2, 1, 4, 3};
    std::vector<int> mid = {1, 2, 3, 4};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<int> preErr = {4, 1, 2, 3};
    std::vector<int> midErr = {1, 4, 3, 2};
    TreeNode * revise = CreateTreePreMid(preErr, midErr);
    recoverTree(revise);

    EXPECT_EQ(isTreeValEqual(root, revise), true);
    FreeTree(root);
    FreeTree(revise);
}

TEST(case_2, content)
{
    std::vector<int> pre = {2, 1, 4, 3};
    std::vector<int> mid = {1, 2, 3, 4};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<int> preErr = {3, 1, 4, 2};
    std::vector<int> midErr = {1, 3, 2, 4};
    TreeNode * revise = CreateTreePreMid(preErr, midErr);
    recoverTree(revise);

    EXPECT_EQ(isTreeValEqual(root, revise), true);
    FreeTree(root);
    FreeTree(revise);
}

TEST(case_11, content)
{
    std::vector<int> pre = {2, 1, 4, 3};
    std::vector<int> mid = {1, 2, 3, 4};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<int> preErr = {4, 1, 2, 3};
    std::vector<int> midErr = {1, 4, 3, 2};
    TreeNode * revise = CreateTreePreMid(preErr, midErr);
    recoverTree1(revise);

    EXPECT_EQ(isTreeValEqual(root, revise), true);
    FreeTree(root);
    FreeTree(revise);
}

TEST(case_21, content)
{
    std::vector<int> pre = {2, 1, 4, 3};
    std::vector<int> mid = {1, 2, 3, 4};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<int> preErr = {3, 1, 4, 2};
    std::vector<int> midErr = {1, 3, 2, 4};
    TreeNode * revise = CreateTreePreMid(preErr, midErr);
    recoverTree1(revise);

    EXPECT_EQ(isTreeValEqual(root, revise), true);
    FreeTree(root);
    FreeTree(revise);
}