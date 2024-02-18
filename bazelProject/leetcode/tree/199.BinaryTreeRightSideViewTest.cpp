#include "199.BinaryTreeRightSideView.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> pre = {1, 2, 5, 3, 4};
    std::vector<int> mid = {2, 5, 1, 3 ,4};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> ans = {1, 3, 4};
    EXPECT_EQ(rightSideView(root), ans);
    EXPECT_EQ(rightSideView1(root), ans);
}