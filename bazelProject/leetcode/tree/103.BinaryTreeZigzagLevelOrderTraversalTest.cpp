#include "gtest/gtest.h"
#include "103.BinaryTreeZigzagLevelOrderTraversal.h"

TEST(case_1, content) {
    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> mid = {9, 3, 15, 20, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<std::vector<int>> ans = {
        {3},
        {20, 9},
        {15, 7}
    };

    EXPECT_EQ(zigzagLevelOrder(root), ans);
    EXPECT_EQ(zigzagLevelOrder1(root), ans);
    FreeTree(root);
}


TEST(case_2, content) {
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<std::vector<int>> ans = {
        {1},
    };

    EXPECT_EQ(zigzagLevelOrder(root), ans);
    EXPECT_EQ(zigzagLevelOrder1(root), ans);
    FreeTree(root);
}

TEST(case_3, content) {
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    std::vector<std::vector<int>> ans = {
    };

    EXPECT_EQ(zigzagLevelOrder(root), ans);
    EXPECT_EQ(zigzagLevelOrder1(root), ans);
    FreeTree(root);
}