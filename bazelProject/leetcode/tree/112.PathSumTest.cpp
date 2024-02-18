#include "gtest/gtest.h"
#include "112.PathSum.h"

TEST(case_1, content) {
    std::vector<int> pre = {5, 4, 11, 7, 2, 8, 13, 4, 1};
    std::vector<int> mid = {7, 11, 2, 4, 5, 13, 8, 4 ,1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 22;
    bool ans = true;
    EXPECT_EQ(hasPathSum(root, targetSum), ans);
    EXPECT_EQ(hasPathSum1(root, targetSum), ans);
    FreeTree(root);
}

TEST(case_2, content) {
    std::vector<int> pre = {5, 4, 11, 7, 2, 8, 13, 4, 1};
    std::vector<int> mid = {7, 11, 2, 4, 5, 13, 8, 4 ,1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 24;
    bool ans = false;
    EXPECT_EQ(hasPathSum(root, targetSum), ans);
    EXPECT_EQ(hasPathSum1(root, targetSum), ans);
    FreeTree(root);
}


TEST(case_3, content) {
    std::vector<int> pre = {1,2,3};
    std::vector<int> mid = {2,1,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 5;
    bool ans = false;
    EXPECT_EQ(hasPathSum(root, targetSum), ans);
    EXPECT_EQ(hasPathSum1(root, targetSum), ans);
    FreeTree(root);
}


TEST(case_4, content) {
    std::vector<int> pre = {1,2,3};
    std::vector<int> mid = {2,1,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 4;
    bool ans = true;
    EXPECT_EQ(hasPathSum(root, targetSum), ans);
    EXPECT_EQ(hasPathSum1(root, targetSum), ans);
    FreeTree(root);
}


TEST(case_5, content) {
    std::vector<int> pre = {1,2,3};
    std::vector<int> mid = {2,1,3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 3;
    bool ans = true;
    EXPECT_EQ(hasPathSum(root, targetSum), ans);
    EXPECT_EQ(hasPathSum1(root, targetSum), ans);
    EXPECT_EQ(hasPathSumNoRecursive(root, targetSum), ans);
    FreeTree(root);
}

TEST(case_6, content) {
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 0;
    bool ans = false;
    EXPECT_EQ(hasPathSum(root, targetSum), ans);
    EXPECT_EQ(hasPathSum1(root, targetSum), ans);
    EXPECT_EQ(hasPathSumNoRecursive(root, targetSum), ans);
    FreeTree(root);
}


TEST(case_7, content) {
    std::vector<int> pre = {1,2};
    std::vector<int> mid = {1,2};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 1;
    bool ans = false;
    EXPECT_EQ(hasPathSum(root, targetSum), ans);
    EXPECT_EQ(hasPathSum1(root, targetSum), ans);
    EXPECT_EQ(hasPathSumNoRecursive(root, targetSum), ans);
    FreeTree(root);
}