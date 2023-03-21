#include "437.PathSumIII.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 3;
    EXPECT_EQ(pathSum(root, 7), ans);
    FreeTree(root);
}

TEST(case_2,content)
{
    std::vector<int> pre = {10, 5, 3, 3, -2, 2, 1, -3, 11};
    std::vector<int> mid = {3, 3, -2, 5, 2, 1, 10, -3, 11};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 3;
    EXPECT_EQ(pathSum(root, 8), ans);
    FreeTree(root);
}

TEST(case_3,content)
{
    std::vector<int> pre = {5, 4, 11, 7, 2, 8, 13, 4, 5, 1};
    std::vector<int> mid = {7, 11, 2, 4, 5, 13, 8, 5, 4, 1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    int ans = 3;
    EXPECT_EQ(pathSum(root, 22), ans);
    FreeTree(root);
}