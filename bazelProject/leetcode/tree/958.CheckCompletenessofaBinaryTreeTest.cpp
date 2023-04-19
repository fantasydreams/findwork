#include "958.CheckCompletenessofaBinaryTree.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    TreeNode * root = nullptr;
    bool ans = true;
    EXPECT_EQ(isCompleteTree(root), ans);
    EXPECT_EQ(isCompleteTree1(root), ans);
}


TEST(case_2,content)
{
    std::vector<int> pre = {10, 5, 3, 1, 7, 6, 15, 13, 18};
    std::vector<int> mid = {1, 3, 5, 6, 7, 10, 13, 15, 18};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = false;
    EXPECT_EQ(isCompleteTree(root), ans);
    EXPECT_EQ(isCompleteTree1(root), ans);
    FreeTree(root);
}


TEST(case_3,content)
{
    std::vector<int> pre = {2,1,3};
    std::vector<int> mid = {1,2,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = true;
    EXPECT_EQ(isCompleteTree(root), ans);
    FreeTree(root);
}

TEST(case_4,content)
{
    std::vector<int> pre = {1,2,3};
    std::vector<int> mid = {2,1,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = true;
    EXPECT_EQ(isCompleteTree(root), ans);
    EXPECT_EQ(isCompleteTree1(root), ans);
    FreeTree(root);
}

TEST(case_5,content)
{
    std::vector<int> pre = {1,2,4,5,3,6,7};
    std::vector<int> mid = {4,2,5,1,6,3,7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = true;
    EXPECT_EQ(isCompleteTree(root), ans);
    EXPECT_EQ(isCompleteTree1(root), ans);
    FreeTree(root);
}

TEST(case_6,content)
{
    std::vector<int> pre = {1,2,4,5,3,6};
    std::vector<int> mid = {4,2,5,1,6,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = true;
    EXPECT_EQ(isCompleteTree(root), ans);
    EXPECT_EQ(isCompleteTree1(root), ans);
    FreeTree(root);
}

TEST(case_7,content)
{
    std::vector<int> pre = {1,2,4,8,5,3,6};
    std::vector<int> mid = {8,4,2,5,1,6,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    bool ans = false;
    EXPECT_EQ(isCompleteTree(root), ans);
    EXPECT_EQ(isCompleteTree1(root), ans);
    FreeTree(root);
}