#include "538.ConvertBSTtoGreaterTree.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> pre = {4, 1, 0, 2, 3, 6, 5, 7, 8};
    std::vector<int> mid = {0, 1, 2, 3, 4, 5, 6, 7 ,8};
    TreeNode * root = CreateTreePreMid(pre, mid);
    TreeNode * convert = convertBST(root);

    std::vector<int> pre1 = {30, 36, 36, 35, 33, 21, 26, 15, 8};
    std::vector<int> mid1 = {36, 36, 35, 33, 30, 26, 21, 15 ,8};

    std::vector<int> conPre, conMid;
    TraverseTreePreNoRecursion(convert, conPre);
    TraverseTreeMidNoRecursion(convert, conMid);
    EXPECT_EQ(conPre, pre1);
    EXPECT_EQ(conMid, mid1);
    FreeTree(convert);
}

TEST(case_2,content)
{
    std::vector<int> pre = {0,1};
    std::vector<int> mid = {0,1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    TreeNode * convert = convertBST(root);

    std::vector<int> pre1 = {1,1};
    std::vector<int> mid1 = {1,1};
    std::vector<int> conPre, conMid;
    TraverseTreePreNoRecursion(convert, conPre);
    TraverseTreeMidNoRecursion(convert, conMid);
    EXPECT_EQ(conPre, pre1);
    EXPECT_EQ(conMid, mid1);
    FreeTree(convert);
}