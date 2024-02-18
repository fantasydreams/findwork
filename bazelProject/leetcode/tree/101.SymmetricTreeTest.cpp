#include "101.SymmetricTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    bool ans = false;
    EXPECT_EQ(isSymmetric(root), ans);
    EXPECT_EQ(isSymmetricIterator(root), ans);
    EXPECT_EQ(isSymmetric2(root), ans);
    EXPECT_EQ(isSymmetricNoRecursor(root), ans);
    FreeTree(root);
}

TEST(case_2, content)
{
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    bool ans = true;
    EXPECT_EQ(isSymmetric(root), ans);
    EXPECT_EQ(isSymmetricIterator(root), ans);
    EXPECT_EQ(isSymmetric2(root), ans);
    EXPECT_EQ(isSymmetricNoRecursor(root), ans);
    FreeTree(root);
}

TEST(case_3, content)
{
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    bool ans = true;
    EXPECT_EQ(isSymmetric(root), ans);
    EXPECT_EQ(isSymmetricIterator(root), ans);
    EXPECT_EQ(isSymmetric2(root), ans);
    EXPECT_EQ(isSymmetricNoRecursor(root), ans);
    FreeTree(root);
}

TEST(case_4, content)
{
    std::vector<int> pre = {1,2};
    std::vector<int> mid = {1,2};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    bool ans = false;
    EXPECT_EQ(isSymmetric(root), ans);
    EXPECT_EQ(isSymmetricIterator(root), ans);
    EXPECT_EQ(isSymmetric2(root), ans);
    EXPECT_EQ(isSymmetricNoRecursor(root), ans);
    FreeTree(root);
}

TEST(case_5, content)
{
    std::vector<int> pre = {1,2,2};
    std::vector<int> mid = {2,1,2};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    bool ans = true;
    EXPECT_EQ(isSymmetric(root), ans);
    EXPECT_EQ(isSymmetricIterator(root), ans);
    EXPECT_EQ(isSymmetric2(root), ans);
    EXPECT_EQ(isSymmetricNoRecursor(root), ans);
    FreeTree(root);
}

TEST(case_6, content)
{
    std::vector<int> pre = {1,2,3,4,2,4,3};
    std::vector<int> mid = {3,2,4,1,4,2,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    bool ans = true;
    EXPECT_EQ(isSymmetric(root), ans);
    EXPECT_EQ(isSymmetricIterator(root), ans);
    EXPECT_EQ(isSymmetric2(root), ans);
    EXPECT_EQ(isSymmetricNoRecursor(root), ans);
    FreeTree(root);
}

TEST(case_7, content)
{
    std::vector<int> pre = {1,2,3,2,3};
    std::vector<int> mid = {2,3,1,2,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    bool ans = false;
    EXPECT_EQ(isSymmetric(root), ans);
    EXPECT_EQ(isSymmetricIterator(root), ans);
    EXPECT_EQ(isSymmetric2(root), ans);
    EXPECT_EQ(isSymmetricNoRecursor(root), ans);
    FreeTree(root);
}

TEST(case_8, content)
{
    std::vector<int> pre = {1,2,3,2,3};
    std::vector<int> mid = {3,2,1,2,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    bool ans = true;
    EXPECT_EQ(isSymmetric(root), ans);
    EXPECT_EQ(isSymmetricIterator(root), ans);
    EXPECT_EQ(isSymmetric2(root), ans);
    EXPECT_EQ(isSymmetricNoRecursor(root), ans);
    FreeTree(root);
}