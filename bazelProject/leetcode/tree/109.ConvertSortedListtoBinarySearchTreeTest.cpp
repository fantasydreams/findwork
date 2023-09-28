#include "109.ConvertSortedListtoBinarySearchTree.h"
#include "gtest/gtest.h"
#include "List/linkcomm.h"


TEST(case_1, content) {
    std::vector<int> pre = {1};
    std::vector<int> mid = {1};
    std::vector<int> sort = {1};
    TreeNode* root = CreateTreePreMid(pre, mid);

    std::vector<int> vec = {1};
    ListNode * list = createLinkList(vec);
    TreeNode* newRoot = sortedListToBST1(list);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
    freeLinkList(list);
}


TEST(case_2, content) {
    std::vector<int> pre = {};
    std::vector<int> mid = {};
    std::vector<int> sort = {};
    TreeNode* root = CreateTreePreMid(pre, mid);
    std::vector<int> vec = {};
    ListNode * list = createLinkList(vec);
    TreeNode* newRoot = sortedListToBST1(list);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
    freeLinkList(list);
}


TEST(case_3, content) {
    std::vector<int> pre = {2,1,3};
    std::vector<int> mid = {1,2,3};
    std::vector<int> sort = {1,2,3};
    TreeNode* root = CreateTreePreMid(pre, mid);
    
    ListNode * list = createLinkList(sort);
    TreeNode* newRoot = sortedListToBST1(list);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
    freeLinkList(list);
}


TEST(case_4, content) {
    std::vector<int> pre = {2,1,3,4};
    std::vector<int> mid = {1,2,3,4};
    std::vector<int> sort = {1,2,3,4};
    TreeNode* root = CreateTreePreMid(pre, mid);
    
    ListNode * list = createLinkList(sort);
    TreeNode* newRoot = sortedListToBST1(list);

    // TraverseTreeLevelDebug(root);
    // printf("\n");
    // TraverseTreeLevelDebug(newRoot);

    EXPECT_EQ(isTreeValEqual(root, newRoot), true);
    FreeTree(root);
    FreeTree(newRoot);
    freeLinkList(list);
}