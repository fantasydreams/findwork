#include "889.ConstructBinaryTreefromPreorderandPostorderTraversal.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> post = {4, 5, 2, 6, 7, 3, 1};
    TreeNode* root1 = constructFromPrePost(pre, post);
    
    EXPECT_EQ(isTreeValEqual(root, root1), true);
    FreeTree(root);
    FreeTree(root1);
}

TEST(case_2, content)
{
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> post = {1};
    TreeNode* root1 = constructFromPrePost(pre, post);
    
    EXPECT_EQ(isTreeValEqual(root, root1), true);
    FreeTree(root);
    FreeTree(root1);
}

TEST(case_3, content)
{
    std::vector<int> pre = {1, 2, 3};
    std::vector<int> mid = {1, 2, 3};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> post = {3, 2, 1};
    TreeNode* root1 = constructFromPrePost(pre, post);
    
    EXPECT_EQ(isTreeValEqual(root, root1), true);
    FreeTree(root);
    FreeTree(root1);
}