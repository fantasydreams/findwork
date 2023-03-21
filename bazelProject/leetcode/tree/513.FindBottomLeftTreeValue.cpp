#include "513.FindBottomLeftTreeValue.h"
#include <queue>

int findBottomLeftValue(TreeNode* root) {
    if(!root) {
        return 0;
    }

    std::queue<TreeNode*> que;
    que.push(root);
    int size = 1;
    int ans;
    while(!que.empty()) {
        for(int i = 0; i < size; ++i){
            TreeNode *node = que.front();
            que.pop();
            // printf("%d ", node->val);
            if(i == 0) {
                ans = node->val;
            }

            if(node->left) {
                que.push(node->left);
            }
            if(node->right) {
                que.push(node->right);
            }
        }
        
        size = que.size();
    }

    return ans;
}