#include "653.TwoSumIVInputisaBST.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int k = 11;
    bool ans = true;
    EXPECT_EQ(findTarget(root, k), ans);
    FreeTree(root);
}

TEST(case_2, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int k = 5;
    bool ans = true;
    EXPECT_EQ(findTarget(root, k), ans);
    FreeTree(root);
}

TEST(case_3, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int k = 1;
    bool ans = false;
    EXPECT_EQ(findTarget(root, k), ans);
    FreeTree(root);
}

TEST(case_4, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int k = 7;
    bool ans = true;
    EXPECT_EQ(findTarget(root, k), ans);
    FreeTree(root);
}

TEST(case_5, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int k = 12;
    bool ans = true;
    EXPECT_EQ(findTarget(root, k), ans);
    FreeTree(root);
}

TEST(case_6, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int k = 2;
    bool ans = false;
    EXPECT_EQ(findTarget(root, k), ans);
    FreeTree(root);
}

TEST(case_7, content)
{
    std::vector<int> pre = {0, -1, -3, 2, 4};
    std::vector<int> mid = {-3, -1, 0, 2, 4};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int k = -4;
    bool ans = true;
    EXPECT_EQ(findTarget(root, k), ans);
    FreeTree(root);
}