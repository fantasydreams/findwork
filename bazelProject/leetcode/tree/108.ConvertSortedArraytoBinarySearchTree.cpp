#include "108.ConvertSortedArraytoBinarySearchTree.h"
#include "treecomm.h"

TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if(start < 0 || end >= nums.size() || start > end) {
        return nullptr;
    }

    int mid = start + ((end - start) >> 1);
    TreeNode * root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}


TreeNode* sortedArrayToBST1(vector<int>& nums, int start, int end) {
    if(start < 0 || end >= nums.size() || start > end) {
        return nullptr;
    }

    int iMid = start + ((end - start) >> 1);
    TreeNode* pRoot = new TreeNode(nums[iMid]);
    pRoot->left = sortedArrayToBST1(nums, start, iMid - 1);
    pRoot->right = sortedArrayToBST1(nums, iMid + 1, end);
    return pRoot;
}

TreeNode* sortedArrayToBST1(vector<int>& nums) {
    return sortedArrayToBST1(nums, 0, nums.size() - 1);
}
