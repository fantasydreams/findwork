#include "145.BinaryTreePostorderTraversal.h"
#include <stack>
#include <vector>

void PushTaskLeftPathUntilNull(TreeNode * root, std::stack<TreeNode *> & stack);


vector<int> postorderTraversal(TreeNode* root) {
    TreeNode * pre = nullptr;
    vector<int> ans;
    std::stack<TreeNode *> st;
    PushTaskLeftPathUntilNull(root, st);
    while(!st.empty()) {
        TreeNode * node = st.top();
        if(node->right == nullptr || (pre && node->right == pre)) {
            ans.push_back(node->val);
            st.pop();
            pre = node;
        }else {
            PushTaskLeftPathUntilNull(node->right, st);
        }
    }

    return ans;
}