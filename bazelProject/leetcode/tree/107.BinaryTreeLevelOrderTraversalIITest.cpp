#include "gtest/gtest.h"
#include "107.BinaryTreeLevelOrderTraversalII.h"


TEST(case_1, content) {
    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> mid = {9, 3, 15, 20, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<std::vector<int>> ans = {
        {15, 7},
        {9, 20},
        {3}
    };

    EXPECT_EQ(levelOrderBottom(root), ans);
    FreeTree(root);
}


TEST(case_2, content) {
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<std::vector<int>> ans = {
        {1}
    };

    EXPECT_EQ(levelOrderBottom(root), ans);
    FreeTree(root);
}


TEST(case_3, content) {
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<std::vector<int>> ans = {
    };

    EXPECT_EQ(levelOrderBottom(root), ans);
    FreeTree(root);
}