#include "104.MaximumDepthofBinaryTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 3;
    EXPECT_EQ(maxDepth(root), ans);
    EXPECT_EQ(maxDepthRecursive(root), ans);
    EXPECT_EQ(maxDepth1(root), ans);
    EXPECT_EQ(maxDepth2(root), ans);

    FreeTree(root);
}
