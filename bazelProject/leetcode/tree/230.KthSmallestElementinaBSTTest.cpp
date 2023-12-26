#include "230.KthSmallestElementinaBST.h"
#include "treecomm.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> pre = {2,1,3};
    std::vector<int> mid = {1,2,3};
    TreeNode * root = CreateTreePreMid(pre, mid);

    int ans = 1;
    EXPECT_EQ(kthSmallest(root, 1), ans);
    FreeTree(root);
}


TEST(case_2, content) {
    std::vector<int> pre = {2,1,3};
    std::vector<int> mid = {1,2,3};
    TreeNode * root = CreateTreePreMid(pre, mid);

    int ans = 2;
    EXPECT_EQ(kthSmallest(root, 2), ans);
    FreeTree(root);
}

TEST(case_3, content) {
    std::vector<int> pre = {2,1,3};
    std::vector<int> mid = {1,2,3};
    TreeNode * root = CreateTreePreMid(pre, mid);

    int ans = 3;
    EXPECT_EQ(kthSmallest(root, 3), ans);
    FreeTree(root);
}