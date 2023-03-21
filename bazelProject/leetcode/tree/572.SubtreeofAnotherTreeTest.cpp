#include "572.SubtreeofAnotherTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {3, 4, 1, 2, 5};
    std::vector<int> mid = {1, 4, 2, 3, 5};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> subPre = {4, 1, 2};
    std::vector<int> subMid = {1, 4, 2};
    TreeNode * subRoot = CreateTreePreMid(subPre, subMid);
    
    EXPECT_EQ(isSubtree(root, subRoot), true);
    FreeTree(root);
    FreeTree(subRoot);
}


TEST(case_2, content)
{
    std::vector<int> pre = {3, 4, 1, 2, 0, 5};
    std::vector<int> mid = {1, 4, 0, 2, 3, 5};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> subPre = {4, 1, 2};
    std::vector<int> subMid = {1, 4, 2};
    TreeNode * subRoot = CreateTreePreMid(subPre, subMid);
    
    EXPECT_EQ(isSubtree(root, subRoot), false);
    FreeTree(root);
    FreeTree(subRoot);
}
