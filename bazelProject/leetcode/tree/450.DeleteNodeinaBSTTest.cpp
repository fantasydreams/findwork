#include "450.DeleteNodeinaBST.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {5, 3, 2, 4, 6, 7};
    std::vector<int> mid = {2, 3, 4, 5, 6, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> pre1 = {5, 4, 2, 6, 7};
    std::vector<int> mid1 = {2, 4, 5, 6, 7};
    TreeNode* root1 = CreateTreePreMid(pre1, mid1);
    
    TreeNode* del = deleteNode(root, 3);
    EXPECT_EQ(isTreeValEqual(del, root1), true);
    FreeTree(del);
    FreeTree(root1);
}


TEST(case_2, content)
{
    std::vector<int> pre = {5};
    std::vector<int> mid = {5};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    TreeNode* del = deleteNode(root, 5), *tmp = nullptr;
    EXPECT_EQ(isTreeValEqual(del, tmp), true);
    FreeTree(del);
}

TEST(case_3, content)
{
    std::vector<int> pre = {5, 3, 2, 4, 6, 7};
    std::vector<int> mid = {2, 3, 4, 5, 6, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> pre1 = {5, 3, 4, 6, 7};
    std::vector<int> mid1 = {3, 4, 5, 6, 7};
    TreeNode* root1 = CreateTreePreMid(pre1, mid1);
    
    TreeNode* del = deleteNode(root, 2);
    EXPECT_EQ(isTreeValEqual(root1, del), true);
    FreeTree(del);
    FreeTree(root1);
}


TEST(case_4, content)
{
    std::vector<int> pre = {5, 3, 2, 4, 6, 7};
    std::vector<int> mid = {2, 3, 4, 5, 6, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> pre1 = {5, 3, 2, 6, 7};
    std::vector<int> mid1 = {2, 3, 5, 6, 7};
    TreeNode* root1 = CreateTreePreMid(pre1, mid1);
    
    TreeNode* del = deleteNode(root, 4);
    EXPECT_EQ(isTreeValEqual(del, root1), true);
    FreeTree(del);
    FreeTree(root1);
}

TEST(case_5, content)
{
    std::vector<int> pre = {5, 3, 2, 4, 6, 7};
    std::vector<int> mid = {2, 3, 4, 5, 6, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> pre1 = {6, 3, 2, 4, 7};
    std::vector<int> mid1 = {2, 3, 4, 6, 7};
    TreeNode* root1 = CreateTreePreMid(pre1, mid1);
    
    TreeNode* del = deleteNode(root, 5);
    EXPECT_EQ(isTreeValEqual(del, root1), true);
    FreeTree(del);
    FreeTree(root1);
}

TEST(case_6, content)
{
    std::vector<int> pre = {5, 3, 2, 4, 6, 8, 7};
    std::vector<int> mid = {2, 3, 4, 5, 8, 6, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> pre1 = {6, 3, 2, 4, 8, 7};
    std::vector<int> mid1 = {2, 3, 4, 8, 6, 7};
    TreeNode* root1 = CreateTreePreMid(pre1, mid1);
    
    TreeNode* del = deleteNode(root, 5);
    EXPECT_EQ(isTreeValEqual(del, root1), true);
    FreeTree(del);
    FreeTree(root1);
}

TEST(case_7, content)
{
    std::vector<int> pre = {1,2};
    std::vector<int> mid = {1,2};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> pre1 = {2};
    std::vector<int> mid1 = {2};
    TreeNode* root1 = CreateTreePreMid(pre1, mid1);
    
    TreeNode* del = deleteNode(root, 1);
    EXPECT_EQ(isTreeValEqual(del, root1), true);
    FreeTree(del);
    FreeTree(root1);
}