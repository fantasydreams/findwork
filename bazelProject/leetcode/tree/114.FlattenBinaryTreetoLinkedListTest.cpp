#include "114.FlattenBinaryTreetoLinkedList.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> pre = {1,2,3,4,5,6};
    std::vector<int> mid = {3,2,4,1,5,6};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    flatten(root);

    std::vector<int> ans;
    TraverseTreePreNoRecursion(root, ans);
    EXPECT_EQ(pre, ans);
    FreeTree(root);
}


TEST(case_2, content) {
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    flatten(root);

    std::vector<int> ans;
    TraverseTreePreNoRecursion(root, ans);
    EXPECT_EQ(pre, ans);
    FreeTree(root);
}

TEST(case_3, content) {
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    flatten(root);

    std::vector<int> ans;
    TraverseTreePreNoRecursion(root, ans);
    EXPECT_EQ(pre, ans);
    FreeTree(root);
}