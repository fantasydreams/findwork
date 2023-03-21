#include "104.MaximumDepthofBinaryTree.h"
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