#include "94.BinaryTreeInorderTraversal.h"
#include <algorithm>
#include <stack>

void PushTaskLeftPathUntilNull(TreeNode * root, std::stack<TreeNode *> & stack);

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    PushTaskLeftPathUntilNull(root, st);
    while(!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        ans.push_back(node->val);
        PushTaskLeftPathUntilNull(node->right, st);
    }

    return ans;
}


void PushTaskLeftPathUntilNull1(TreeNode * root, std::stack<TreeNode *> & stack) {
    while(root) {
        stack.push(root);
        root = root = root->left;
    }
}


vector<int> inorderTraversal1(TreeNode* root) { 
    vector<int> ans;
    std::stack<TreeNode*> st;
    PushTaskLeftPathUntilNull1(root, st);
    while(!st.empty()) {
        TreeNode* pNode = st.top();
        st.pop();
        ans.push_back(pNode->val);
        PushTaskLeftPathUntilNull1(pNode->right, st);    
    }

    return ans;
}