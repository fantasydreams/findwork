#include "112.PathSum.h"
#include "treecomm.h"

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

void hasPathSum1(TreeNode *root, int targetSum, int curSum, bool& bExist) {
    if(root == nullptr) {
        return;
    }

    if(root->left == nullptr && root->right == nullptr) {
        if(targetSum == curSum + root->val) {
            bExist = true;
            return;
        }
    }

    if(!bExist) {
        hasPathSum1(root->left, targetSum, curSum + root->val, bExist);
    }
    if(!bExist) {
        hasPathSum1(root->right, targetSum, curSum + root->val, bExist);
    }
}

bool hasPathSum1(TreeNode* root, int targetSum) {
    if(root == nullptr) {
        return false;
    }

    bool bExist = false;
    hasPathSum1(root, targetSum, 0, bExist);
    return bExist;
}


bool hasPathSumNoRecursive(TreeNode *root, int targetSum) {
    if(root == nullptr) {
        return false;
    }

    std::queue<TreeNode*> que; que.push(root);
    std::queue<int> que_val; que_val.push(root->val);
    while(!que.empty()) {
        TreeNode* pNode = que.front(); que.pop();
        int iVal = que_val.front(); que_val.pop();
        if(pNode->left == nullptr && pNode->right == nullptr) {
            if(iVal == targetSum) {
                return true;
            }
            continue;
        }

        if(pNode->left) {
            que.push(pNode->left);
            que_val.push(iVal + pNode->left->val);
        }
        if(pNode->right) {
            que.push(pNode->right);
            que_val.push(iVal + pNode->right->val);
        }
    }

    return false;
}