#include "897.IncreasingOrderSearchTree.h"
#include <stack>

void PushTaskLeftPathUntilNull(TreeNode * root, std::stack<TreeNode *> & stack);

TreeNode* increasingBST(TreeNode* root) {   
    std::stack<TreeNode*> st;
    TreeNode* newroot = nullptr;
    TreeNode* pre = nullptr;
    PushTaskLeftPathUntilNull(root, st);
    while(!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if(newroot == nullptr) {
            newroot = node;
        }
        if(pre) {
            pre->right = node;
        }
        pre = node;
        node->left = nullptr;
        PushTaskLeftPathUntilNull(node->right, st);
    }

    return newroot;
}