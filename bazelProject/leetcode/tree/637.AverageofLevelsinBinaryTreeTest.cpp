#include "637.AverageofLevelsinBinaryTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    std::vector<double> ans = {1,2.5,5.5};
    std::vector<double> ans1= averageOfLevels(root);
    EXPECT_EQ(ans, ans1);
    FreeTree(root);
}