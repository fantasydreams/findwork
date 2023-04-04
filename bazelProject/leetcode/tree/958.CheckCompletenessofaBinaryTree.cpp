#include "958.CheckCompletenessofaBinaryTree.h"
#include <queue>


bool isCompleteTree(TreeNode* root) {
    if(!root) {
        return true;
    }

    std::queue<TreeNode*> que;
    que.push(root);
    int levelNodes = 1;
    while(!que.empty()) {
        bool bNull = false;
        bool nextLevleNotNull = false;
        for(int i = 0; i < levelNodes; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if(node) {
                if(bNull) {
                    return false;
                }
                que.push(node->left);   
                que.push(node->right);
                if(node->left || node->right) {
                    nextLevleNotNull = true;
                }

            }else {
                bNull = true;
            }
        }
        levelNodes = que.size();
        if(bNull && nextLevleNotNull) {
            return false;
        }
    }
    return true;
}