#include "104.MaximumDepthofBinaryTree.h"
#include <cstddef>
#include <queue>

int maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    std::queue<TreeNode *> que;
    que.push(root);
    int size = 1;
    int ans = 0;
    while(!que.empty()) {
        ++ans;
        for(int i = 0; i < size; ++i) {
            TreeNode * node = que.front();
            que.pop();
            if(node -> left) {
                que.push(node->left);
            }
            if(node -> right) {
                que.push(node->right);
            }
        }
        size = que.size();
    }

    return ans;
}


int maxDepthRecursive(TreeNode* root) { 
    if(root == nullptr) {
        return 0;
    }
    return std::max(maxDepthRecursive(root ->left), maxDepthRecursive(root -> right)) + 1;
}

int maxDepth1(TreeNode* root) { // 2023/9/26
    int ans = 0;
    if(root == NULL) {
        return ans;
    }    

    std::queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
        int size = que.size();
        while(size) {
            TreeNode* pNode = que.front(); que.pop();
            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
            --size;
        }
        ++ans;
    }
    return ans;
}