#include "129.SumRoottoLeafNumbers.h"
#include "treecomm.h"


void GetsumNumbers(TreeNode* root, int curSum, int& ans) {
    if(!root) {
        return;
    }

    if(root->left == nullptr && root->right == nullptr) {
        ans += curSum * 10 + root->val;
        return;
    }

    curSum = curSum * 10 + root->val;
    GetsumNumbers(root->left, curSum, ans);
    GetsumNumbers(root->right, curSum, ans);
}

int sumNumbers(TreeNode* root) {
    int ans = 0, curSum = 0;
    GetsumNumbers(root, curSum, ans);
    return ans;
}