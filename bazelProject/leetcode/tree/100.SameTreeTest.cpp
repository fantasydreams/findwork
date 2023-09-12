#include "100.SameTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {2, 1, 4, 3};
    std::vector<int> mid = {1, 2, 3, 4};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<int> preErr = {4, 1, 2, 3};
    std::vector<int> midErr = {1, 4, 3, 2};
    TreeNode * revise = CreateTreePreMid(preErr, midErr);

    EXPECT_EQ(isSameTree(root, revise), false);
    FreeTree(root);
    FreeTree(revise);
}

TEST(case_2, content)
{
    std::vector<int> pre = {2, 1, 4, 3};
    std::vector<int> mid = {1, 2, 3, 4};
    TreeNode * root = CreateTreePreMid(pre, mid);
    TreeNode * revise = CreateTreePreMid(pre, mid);

    EXPECT_EQ(isSameTree(root, revise), true);
    FreeTree(root);
    FreeTree(revise);
}