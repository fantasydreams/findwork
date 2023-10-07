#include "124.BinaryTreeMaximumPathSum.h"
#include "gtest/gtest.h"
#include "treecomm.h"

TEST(case_1, content) {
    std::vector<int> pre = {1,2,3};
    std::vector<int> mid = {2,1,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 6;
    EXPECT_EQ(maxPathSum(root), ans);
    FreeTree(root);
}


TEST(case_2, content) {
    std::vector<int> pre = {-10, 9, 20, 15, 7};
    std::vector<int> mid = {9, -10, 15, 20, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 42;
    EXPECT_EQ(maxPathSum(root), ans);
    FreeTree(root);
}