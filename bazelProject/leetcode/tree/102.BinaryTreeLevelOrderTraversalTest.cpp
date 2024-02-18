
#include "102.BinaryTreeLevelOrderTraversal.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> mid = {9, 3, 15, 20, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    vector<vector<int>> ans = {{3},{9,20}, {15, 7}};
    EXPECT_EQ(ans, levelOrder(root));
    EXPECT_EQ(ans, levelOrder1(root));

    FreeTree(root);
}