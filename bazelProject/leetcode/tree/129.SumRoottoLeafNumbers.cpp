#include "129.SumRoottoLeafNumbers.h"
#include "treecomm.h"
#include <queue>

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


int sumNumbers1(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int iAns = 0;
    std::queue<TreeNode*> que; que.push(root);
    std::queue<int> que_val; que_val.push(root->val);
    while(!que.empty()) {
        TreeNode* node = que.front(); que.pop();
        int val = que_val.front(); que_val.pop();
        if(node->left == nullptr && node->right == nullptr) {
            iAns += val;
            continue;
        }            

        if(node->left) {
            que.push(node->left);
            que_val.push(val * 10 + node->left->val);
        }
        if(node->right) {
            que.push(node->right);
            que_val.push(val * 10 + node->right->val);
        }
    }

    return iAns;
}