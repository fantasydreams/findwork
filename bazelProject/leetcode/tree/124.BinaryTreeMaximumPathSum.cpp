#include "124.BinaryTreeMaximumPathSum.h"
#include <climits>

int maxPathSum(TreeNode* root, int& max) {
    if(!root) {
        return 0;
    }
    int left = maxPathSum(root->left, max);
    int right = maxPathSum(root->right, max);

    left = left > 0 ? left : 0;
    right = right > 0 ? right : 0;
    int _max = left + right + root->val;
    max = std::max(_max, max);
    return std::max(left, right) + root->val > 0 ? std::max(left, right) + root->val : 0;
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    maxPathSum(root, ans);
    return ans;
}


int maxPathSum1(TreeNode* root, int& max) {
    if(root == nullptr) {
        return 0;
    }

    int iLeftVal = std::max(maxPathSum1(root->left, max), 0);
    int iRightVal = std::max(maxPathSum1(root->right, max), 0);
    max = std::max(iLeftVal + iRightVal + root->val, max);
    int iTmp = std::max(iLeftVal, iRightVal) + root->val;
    return iTmp > 0 ? iTmp : 0;
}

int maxPathSum1(TreeNode* root) {
    int iAns = INT_MIN;
    maxPathSum1(root, iAns);
    return iAns;
}