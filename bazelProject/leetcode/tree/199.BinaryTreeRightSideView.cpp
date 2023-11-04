#include "199.BinaryTreeRightSideView.h"

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