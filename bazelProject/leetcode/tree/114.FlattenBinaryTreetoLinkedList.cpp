#include "treecomm.h"
#include <stack>


void flatten(TreeNode* root) {
    if(root == nullptr) {
        return;
    }

    std::stack<TreeNode*> st; st.push(root);
    TreeNode* pPre = nullptr;
    while(!st.empty()) {
        TreeNode* pNode = st.top(); st.pop();
        if(pPre) {
            pPre->right = pNode;
        }
        
        if(pNode->right) {
            st.push(pNode->right);
        }
        if(pNode->left) {
            st.push(pNode->left);
        }

        pPre = pNode;
        pNode->left = nullptr;
    }
}

void flatten1(TreeNode* root) {
    std::stack<TreeNode*> st;
    if(root) {
        st.push(root);
    }
    TreeNode *pPre = nullptr;
    while(!st.empty()) {
        TreeNode* pNode = st.top(); st.pop();
        if(pPre) {
            pPre->right = pNode;
        }
        if(pNode->right) {
            st.push(pNode->right);
        }
        if(pNode->left) {
            st.push(pNode->left);
        }
        pPre = pNode;
        pNode->left = nullptr;
    }
}