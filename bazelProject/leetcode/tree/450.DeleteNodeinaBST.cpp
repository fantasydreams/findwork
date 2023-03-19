#include "450.DeleteNodeinaBST.h"
#include <stack>

void pushLeftUtillNull(TreeNode* root, std::stack<TreeNode*> & st) {
    while(root) {
        st.push(root);
        root = root->left;
    }
}

TreeNode * getRightUntilNull(TreeNode* root) {
    while(root && root->right) {
        root = root->right;
    }

    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    std::stack<TreeNode *> st;
    pushLeftUtillNull(root, st);
    TreeNode* pre = nullptr;
    while(!st.empty()) {
        TreeNode* node = st.top();
        if(node->right == nullptr || (pre && pre == node->right)) {
            st.pop();
            pre = node;
            if(node->val == key) {
                if(node->left == nullptr || node->right == nullptr) {
                    TreeNode * ans = node->left == nullptr ? node->right : node->left;
                    if(st.empty()) {
                        delete node;
                        return ans;
                    }else {
                        if(st.top()->left == node) { //左子树
                            st.top()->left = ans;
                        }else { //右子树
                            st.top()->right = ans;
                        }
                        delete node;
                    }
                }else {
                    TreeNode * tmp = getRightUntilNull(node->left);
                    tmp->right = node->right->left;
                    node->right->left = node->left;
                    TreeNode *ans = node->right;
                    if(st.empty()) {
                        delete node;
                        return ans;
                    }else{
                        if(st.top()->left == node) { //左子树
                            st.top()->left = ans;
                        }else { //右子树
                            st.top()->right = ans;
                        }
                        delete node;
                    }
                }
            }
            pre = node;
        }else {
            pushLeftUtillNull(node->right, st);
        }
    }

    return root;
}