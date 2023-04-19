#include "98.ValidateBinarySearchTree.h"
#include <climits>
#include <stack>

void pushLeftUntilNull(TreeNode* root, std::stack<TreeNode*>& st) {
    while(root) {
        st.push(root);
        root = root->left;
    }
}

bool isValidBST(TreeNode* root) {
    if(!root) {
        return true;
    }

    int64_t iPreNum = INT64_MIN;
    std::stack<TreeNode*> st;
    pushLeftUntilNull(root, st);
    while(!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if(node->val <= iPreNum) {
            return false;
        }
        iPreNum = node->val;
        pushLeftUntilNull(node->right, st);
    }

    return true;
}