#include "gtest/gtest.h"
#include "113.PathSumII.h"

TEST(case_1, content) {
    std::vector<int> pre = {5, 4, 11, 7, 2, 8, 13, 4, 1};
    std::vector<int> mid = {7, 11, 2, 4, 5, 13, 8, 4 ,1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 22;
    std::vector<std::vector<int>> ans = {
        {5,4,11,2}
    };

    EXPECT_EQ(pathSum(root, targetSum), ans);
    FreeTree(root);
}


TEST(case_2, content) {
    std::vector<int> pre = {5, 4, 11, 7, 2, 8, 13, 4, 5, 1};
    std::vector<int> mid = {7, 11, 2, 4, 5, 13, 8, 5, 4 ,1};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 22;
    std::vector<std::vector<int>> ans = {
        {5,4,11,2},
        {5,8,4,5}
    };

    EXPECT_EQ(pathSum(root, targetSum), ans);
    FreeTree(root);
}


TEST(case_7, content) {
    std::vector<int> pre = {1,2};
    std::vector<int> mid = {1,2};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int targetSum = 1;
    std::vector<std::vector<int>> ans;
    EXPECT_EQ(pathSum(root, targetSum), ans);
    FreeTree(root);
}