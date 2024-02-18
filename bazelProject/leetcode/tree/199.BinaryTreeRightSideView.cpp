#include "199.BinaryTreeRightSideView.h"
#include "treecomm.h"

vector<int> rightSideView(TreeNode* root) {
    std::vector<int> ans;
    if(!root) {
        return ans;
    }

    std::queue<TreeNode*> que;que.push(root);
    while(!que.empty()) {
        int size = que.size();
        for(int i = 0; i < size; ++i) {
            TreeNode* pNode = que.front(); que.pop();
            if(i == size - 1) {
                ans.push_back(pNode->val);
            }

            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        }
    }

    return ans;
}

vector<int> rightSideView1(TreeNode* root) {
    std::vector<int> vecAns;
    if(root == nullptr) {
        return vecAns;
    }

    std::queue<TreeNode*> que; que.push(root);
    while(!que.empty()) {
        int iSize = que.size();
        while(iSize--) {
            TreeNode* pNode = que.front(); que.pop();
            if(iSize == 0) {
                vecAns.push_back(pNode->val);
            }

            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        }
    }

    return vecAns;
}