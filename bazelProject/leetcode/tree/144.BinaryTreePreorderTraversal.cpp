#include "144.BinaryTreePreorderTraversal.h"
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