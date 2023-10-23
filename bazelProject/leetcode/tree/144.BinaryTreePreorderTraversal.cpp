#include "144.BinaryTreePreorderTraversal.h"
#include "treecomm.h"
#include <stack>
using namespace std;

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode *> st; 
    if(root) {
        st.push(root);
    }
    while(!st.empty()) {
        TreeNode * node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right) {
            st.push(node->right);
        }
        if(node->left) {
            st.push(node->left);
        }
    }

    return ans;
}


vector<int> preorderTraversal1(TreeNode* root) {
    std::vector<int> ans;
    if(root == nullptr) {
        return ans;
    }

    std::stack<TreeNode*> st; st.push(root);
    while(!st.empty()) {
        TreeNode* pNode = st.top(); st.pop();
        ans.push_back(pNode->val);
        if(pNode->right) {
            st.push(pNode->right);
        }
        if(pNode->left) {
            st.push(pNode->left);
        }
    }

    return ans;
}