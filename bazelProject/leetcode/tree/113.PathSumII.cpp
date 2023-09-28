#include "113.PathSumII.h"
#include <vector>

void pathSum(TreeNode *root, int targetSum, int curSum, std::vector<int>& curPath, std::vector<std::vector<int> >& ans) {
    if(!root) {
        return;
    }

    curPath.push_back((root->val));
    if(!root->left && !root->right) {
        if(curSum + root->val == targetSum) {
            ans.push_back(curPath);
        }
    }

    if(root->left) {
        pathSum(root->left, targetSum, curSum + root->val, curPath, ans);
    }
    if(root->right) {
        pathSum(root->right, targetSum, curSum + root->val, curPath, ans);
    }

    curPath.pop_back();    
}

vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
    vector<vector<int> > ans;
    std::vector<int> curPath;
    pathSum(root, targetSum, 0, curPath, ans);
    return ans;
}