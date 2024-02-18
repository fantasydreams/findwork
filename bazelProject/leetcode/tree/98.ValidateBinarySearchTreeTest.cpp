#include "98.ValidateBinarySearchTree.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    TreeNode * root = nullptr;
    bool ans = true;
    EXPECT_EQ(isValidBST(root), ans);
    EXPECT_EQ(isValidBST2(root), ans);
}


TEST(case_2,content)
{
    std::vector<int> pre = {10, 5, 3, 1, 7, 6, 15, 13, 18};
    std::vector<int> mid = {1, 3, 5, 6, 7, 10, 13, 15, 18};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = true;
    EXPECT_EQ(isValidBST(root), ans);
    EXPECT_EQ(isValidBST1(root), ans);
    EXPECT_EQ(isValidBST2(root), ans);
    FreeTree(root);
}


TEST(case_3,content)
{
    std::vector<int> pre = {2,1,3};
    std::vector<int> mid = {1,2,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = true;
    EXPECT_EQ(isValidBST(root), ans);
    EXPECT_EQ(isValidBST1(root), ans);
    EXPECT_EQ(isValidBST2(root), ans);
    FreeTree(root);
}

TEST(case_4,content)
{
    std::vector<int> pre = {1,2,3};
    std::vector<int> mid = {2,1,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = false;
    EXPECT_EQ(isValidBST(root), ans);
    EXPECT_EQ(isValidBST1(root), ans);
    EXPECT_EQ(isValidBST2(root), ans);
    FreeTree(root);
}

TEST(case_5,content)
{
    std::vector<int> pre = {2,2,2};
    std::vector<int> mid = {2,2,2};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = false;
    EXPECT_EQ(isValidBST(root), ans);
    EXPECT_EQ(isValidBST1(root), ans);
    EXPECT_EQ(isValidBST2(root), ans);
    FreeTree(root);
}