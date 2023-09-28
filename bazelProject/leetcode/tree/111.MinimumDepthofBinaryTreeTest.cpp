#include "111.MinimumDepthofBinaryTree.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> mid = {9, 3, 15, 20, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 2;
    EXPECT_EQ(minDepth(root), ans);
    FreeTree(root);
}

TEST(case_2, content) {
    std::vector<int> pre = {3};
    std::vector<int> mid = {3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 1;
    EXPECT_EQ(minDepth(root), ans);
    FreeTree(root);
}


TEST(case_3, content) {
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 0;
    EXPECT_EQ(minDepth(root), ans);
    FreeTree(root);
}