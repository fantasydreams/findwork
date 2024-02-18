
#include "102.BinaryTreeLevelOrderTraversal.h"
#include "treecomm.h"
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


vector<vector<int> > levelOrder1(TreeNode* root) {
    vector<vector<int> > vecAns;
    if(root == nullptr) {
        return vecAns;
    }   

    std::queue<TreeNode*> que; que.push(root);
    while(!que.empty()) {
        int iSize = que.size();
        std::vector<int> vecLevel;
        while(iSize--) {
            TreeNode* pNode = que.front(); que.pop();
            vecLevel.push_back(pNode->val);
            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        }
        vecAns.emplace_back(std::move(vecLevel));
    }

    return vecAns;
}