#include "257.BinaryTreePaths.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 5, 3};
    std::vector<int> mid = {2, 5, 1, 3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<std::string> ans = {"1->2->5","1->3"};
    EXPECT_EQ(binaryTreePaths(root), ans);
    FreeTree(root);
}


TEST(case_2, content)
{
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<std::string> ans = {"1"};
    EXPECT_EQ(binaryTreePaths(root), ans);
    FreeTree(root);
}