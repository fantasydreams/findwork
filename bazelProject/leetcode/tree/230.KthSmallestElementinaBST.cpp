#include "230.KthSmallestElementinaBST.h"
#include "treecomm.h"
#include <stack>

void PushTaskLeftPathUntilNull(TreeNode * root, std::stack<TreeNode *> & stack);

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> st;
    PushTaskLeftPathUntilNull(root, st);
    while(!st.empty()) {
        TreeNode * pNode = st.top(); st.pop();
        if(--k == 0) {
            return pNode->val;
        }

        PushTaskLeftPathUntilNull(pNode->right, st);
    }

    return -1;
}