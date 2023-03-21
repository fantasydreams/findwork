#include "106.ConstructBinaryTreefromInorderandPostorderTraversal.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> mid = {9, 3, 15, 20, 7};
    std::vector<int> post = {9, 15, 7, 20, 3};
    TreeNode * root = CreateTreeMidPost(mid, post);
    TreeNode * newRoot = buildTree(mid, post);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
}