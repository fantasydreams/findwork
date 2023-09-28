#include "108.ConvertSortedArraytoBinarySearchTree.h"

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