#include "226.InvertBinaryTree.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;

TEST(case_2,content)
{
    std::vector<int> pre = {4, 2, 1, 3, 7, 6, 9};
    std::vector<int> mid = {1, 2, 3, 4, 6, 7, 9};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> preReverse = {4, 7, 9, 6, 2, 3, 1};
    std::vector<int> midReverse = {9, 7, 6, 4, 3, 2, 1};
    TreeNode * revert = CreateTreePreMid(preReverse, midReverse);

    TreeNode * reverted = invertTree(root);
    EXPECT_EQ(isTreeValEqual(reverted, revert), true);
    FreeTree(root);
    FreeTree(revert);
}

TEST(case_3, content)
{
    std::vector<int> pre = {2, 1, 3, 5};
    std::vector<int> mid = {1, 2, 3, 5};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> preReverse = {2, 3, 5, 1};
    std::vector<int> midReverse = {5, 3, 2, 1};
    TreeNode * revert = CreateTreePreMid(preReverse, midReverse);

    TreeNode * reverted = invertTree(root);
    EXPECT_EQ(isTreeValEqual(reverted, revert), true);
    FreeTree(root);
    FreeTree(revert);
}

TEST(case_4,content)
{
    std::vector<int> pre = {4, 2, 1, 3, 7, 6, 9};
    std::vector<int> mid = {1, 2, 3, 4, 6, 7, 9};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> preReverse = {4, 7, 9, 6, 2, 3, 1};
    std::vector<int> midReverse = {9, 7, 6, 4, 3, 2, 1};
    TreeNode * revert = CreateTreePreMid(preReverse, midReverse);

    TreeNode * reverted = invertTreeNoRecursion(root);
    EXPECT_EQ(isTreeValEqual(reverted, revert), true);
    FreeTree(root);
    FreeTree(revert);
}

TEST(case_5, content)
{
    std::vector<int> pre = {2, 1, 3, 5};
    std::vector<int> mid = {1, 2, 3, 5};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> preReverse = {2, 3, 5, 1};
    std::vector<int> midReverse = {5, 3, 2, 1};
    TreeNode * revert = CreateTreePreMid(preReverse, midReverse);

    TreeNode * reverted = invertTreeNoRecursion(root);
    EXPECT_EQ(isTreeValEqual(reverted, revert), true);
    FreeTree(root);
    FreeTree(revert);
}


TEST(case_4,content1)
{
    std::vector<int> pre = {4, 2, 1, 3, 7, 6, 9};
    std::vector<int> mid = {1, 2, 3, 4, 6, 7, 9};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> preReverse = {4, 7, 9, 6, 2, 3, 1};
    std::vector<int> midReverse = {9, 7, 6, 4, 3, 2, 1};
    TreeNode * revert = CreateTreePreMid(preReverse, midReverse);

    TreeNode * reverted = invertTree1(root);
    EXPECT_EQ(isTreeValEqual(reverted, revert), true);
    FreeTree(root);
    FreeTree(revert);
}

TEST(case_5, content1)
{
    std::vector<int> pre = {2, 1, 3, 5};
    std::vector<int> mid = {1, 2, 3, 5};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> preReverse = {2, 3, 5, 1};
    std::vector<int> midReverse = {5, 3, 2, 1};
    TreeNode * revert = CreateTreePreMid(preReverse, midReverse);

    TreeNode * reverted = invertTree1(root);
    EXPECT_EQ(isTreeValEqual(reverted, revert), true);
    FreeTree(root);
    FreeTree(revert);
}


TEST(case_4,content2)
{
    std::vector<int> pre = {4, 2, 1, 3, 7, 6, 9};
    std::vector<int> mid = {1, 2, 3, 4, 6, 7, 9};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> preReverse = {4, 7, 9, 6, 2, 3, 1};
    std::vector<int> midReverse = {9, 7, 6, 4, 3, 2, 1};
    TreeNode * revert = CreateTreePreMid(preReverse, midReverse);

    TreeNode * reverted = invertTreeNoRecursion1(root);
    EXPECT_EQ(isTreeValEqual(reverted, revert), true);
    FreeTree(root);
    FreeTree(revert);
}

TEST(case_5, content2)
{
    std::vector<int> pre = {2, 1, 3, 5};
    std::vector<int> mid = {1, 2, 3, 5};
    TreeNode * root = CreateTreePreMid(pre, mid);

    std::vector<int> preReverse = {2, 3, 5, 1};
    std::vector<int> midReverse = {5, 3, 2, 1};
    TreeNode * revert = CreateTreePreMid(preReverse, midReverse);

    TreeNode * reverted = invertTreeNoRecursion1(root);
    EXPECT_EQ(isTreeValEqual(reverted, revert), true);
    FreeTree(root);
    FreeTree(revert);
}