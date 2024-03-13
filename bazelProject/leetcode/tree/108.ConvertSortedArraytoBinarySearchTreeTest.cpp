#include "gtest/gtest.h"
#include "108.ConvertSortedArraytoBinarySearchTree.h"
#include "treecomm.h"

TEST(case_1, content) {
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    std::vector<int> sort = {1};
    TreeNode* root = CreateTreePreMid(pre, mid);
    TreeNode* newRoot = sortedArrayToBST(sort);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_2, content) {
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    std::vector<int> sort = {};
    TreeNode* root = CreateTreePreMid(pre, mid);
    TreeNode* newRoot = sortedArrayToBST(sort);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_3, content) {
    std::vector<int> pre = {2,1,3};
    std::vector<int> mid = {1,2,3};
    std::vector<int> sort = {1,2,3};
    TreeNode* root = CreateTreePreMid(pre, mid);
    TreeNode* newRoot = sortedArrayToBST(sort);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_4, content) {
    std::vector<int> pre = {2,1,3,4};
    std::vector<int> mid = {1,2,3,4};
    std::vector<int> sort = {1,2,3,4};
    TreeNode* root = CreateTreePreMid(pre, mid);
    TreeNode* newRoot = sortedArrayToBST(sort);

    // TraverseTreeLevelDebug(root);
    // printf("\n");
    // TraverseTreeLevelDebug(newRoot);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_1, content1) {
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    std::vector<int> sort = {1};
    TreeNode* root = CreateTreePreMid(pre, mid);
    TreeNode* newRoot = sortedArrayToBST1(sort);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_2, content1) {
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    std::vector<int> sort = {};
    TreeNode* root = CreateTreePreMid(pre, mid);
    TreeNode* newRoot = sortedArrayToBST1(sort);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_3, content1) {
    std::vector<int> pre = {2,1,3};
    std::vector<int> mid = {1,2,3};
    std::vector<int> sort = {1,2,3};
    TreeNode* root = CreateTreePreMid(pre, mid);
    TreeNode* newRoot = sortedArrayToBST1(sort);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}


TEST(case_4, content1) {
    std::vector<int> pre = {2,1,3,4};
    std::vector<int> mid = {1,2,3,4};
    std::vector<int> sort = {1,2,3,4};
    TreeNode* root = CreateTreePreMid(pre, mid);
    TreeNode* newRoot = sortedArrayToBST1(sort);

    // TraverseTreeLevelDebug(root);
    // printf("\n");
    // TraverseTreeLevelDebug(newRoot);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}