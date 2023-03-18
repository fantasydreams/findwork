#include "538.ConvertBSTtoGreaterTree.h"
#include <stack>

void pushRightUntilNull(TreeNode* node, std::stack<TreeNode*> &st) {
    while(node != nullptr) {
        st.push(node);
        node = node->right;
    }
}

TreeNode* convertBST(TreeNode* root) {
    int64_t upperVal = 0;
    std::stack<TreeNode*> st;
    TreeNode * node;
    pushRightUntilNull(root, st);
    while(!st.empty()) {
        node = st.top(); st.pop();
        node->val = node->val + upperVal;
        upperVal = node->val;
        pushRightUntilNull(node->left, st);
    }

    return root;
}