#include "129.SumRoottoLeafNumbers.h"
#include "treecomm.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> pre = {1, 2, 3};
    std::vector<int> mid = {2, 1, 3};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 25; 
    EXPECT_EQ(sumNumbers(root), ans);
    EXPECT_EQ(sumNumbers1(root), ans);
    FreeTree(root);
}


TEST(case_2, content) {
    std::vector<int> pre = {4, 9, 5, 1, 0};
    std::vector<int> mid = {5, 9, 1, 4, 0};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    int ans = 1026; 
    EXPECT_EQ(sumNumbers(root), ans);
    EXPECT_EQ(sumNumbers1(root), ans);
    FreeTree(root);
}