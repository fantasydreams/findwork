#include "94.BinaryTreeInorderTraversal.h"
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