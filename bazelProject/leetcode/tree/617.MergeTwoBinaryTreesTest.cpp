#include "617.MergeTwoBinaryTrees.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre1 = {1, 3, 5, 4};
    std::vector<int> mid1 = {5, 3, 1, 4};
    TreeNode * root1 = CreateTreePreMid(pre1, mid1);
    TraverseTreePreNoRecursion(root1); printf("\n");
    TraverseTreeMid(root1);printf("\n");printf("\n");

    std::vector<int> pre2 = {2, 1, 6, 4, 7};
    std::vector<int> mid2 = {1, 6, 2, 4, 7};
    TreeNode * root2 = CreateTreePreMid(pre2, mid2);
    TraverseTreePreNoRecursion(root2);printf("\n");
    TraverseTreeMid(root2);printf("\n");printf("\n");

    std::vector<int> pre3 = {3, 4, 5, 6, 8, 7};
    std::vector<int> mid3 = {5, 4, 6, 3, 8, 7};
    TreeNode * root3 = CreateTreePreMid(pre3, mid3);
    TraverseTreePreNoRecursion(root3);printf("\n");
    TraverseTreeMid(root3);printf("\n");printf("\n");
    
    TreeNode * merge = mergeTrees(root1, root2);
    TraverseTreePreNoRecursion(merge);printf("\n");
    TraverseTreeMid(merge);printf("\n");printf("\n");
    EXPECT_EQ(isTreeValEqual(merge, root3), true);
    FreeTree(root1);
    FreeTree(root2);
    FreeTree(root3);
}

TEST(case_2, content)
{
    std::vector<int> pre1 = {1};
    std::vector<int> mid1 = {1};
    TreeNode * root1 = CreateTreePreMid(pre1, mid1);
    TraverseTreePreNoRecursion(root1);printf("\n");
    TraverseTreeMid(root1);printf("\n");printf("\n");

    std::vector<int> pre2 = {1,2};
    std::vector<int> mid2 = {1,2};
    TreeNode * root2 = CreateTreePreMid(pre2, mid2);
    TraverseTreePreNoRecursion(root2);printf("\n");
    TraverseTreeMid(root2);printf("\n");printf("\n");

    std::vector<int> pre3 = {2,2};
    std::vector<int> mid3 = {2,2};
    TreeNode * root3 = CreateTreePreMid(pre3, mid3);
    TraverseTreePreNoRecursion(root3);printf("\n");
    TraverseTreeMid(root3);printf("\n");printf("\n");
    
    TreeNode * merge = mergeTrees(root1, root2);
    TraverseTreePreNoRecursion(merge);printf("\n");
    TraverseTreeMid(merge);printf("\n");printf("\n");
    EXPECT_EQ(isTreeValEqual(merge, root3), true);
    FreeTree(root1);
    FreeTree(root2);
    FreeTree(root3);
}