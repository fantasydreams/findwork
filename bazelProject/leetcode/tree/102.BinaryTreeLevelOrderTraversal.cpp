
#include "102.BinaryTreeLevelOrderTraversal.h"
#include <queue>

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > ans;   
    if(!root) {
        return ans; 
    }

    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()) {
        int size = que.size();
        std::vector<int> vec;
        for(int i = 0; i < size; ++i) {
            TreeNode* pNode = que.front();
            vec.push_back(pNode->val);
            que.pop();
            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
        }
        
        ans.push_back(vec);
    }

    return ans;
}