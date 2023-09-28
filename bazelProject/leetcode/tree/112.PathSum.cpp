#include "112.PathSum.h"

void hasPathSum(TreeNode *root, int targetSum, int curSum, bool& bExist) {
    if(!root) {
        bExist = false;
        return;
    }

    if(root->left == nullptr && root->right == nullptr) {
        if(targetSum == curSum + root->val) {
            bExist = true;
        }else {
            bExist = false;
        }
        return;   
    }

    if(!bExist && root->left) {
        hasPathSum(root->left, targetSum, curSum + root->val, bExist);
    }
    if(!bExist && root->right) {
        hasPathSum(root->right, targetSum, curSum + root->val, bExist);
    }
}


bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr) {
        return false;
    }
    bool bExist = false;
    hasPathSum(root, targetSum, 0, bExist);
    return bExist;
}