#include "653.TwoSumIVInputisaBST.h"
#include <stack>

void pushLeftUtillNull(TreeNode* root, std::stack<TreeNode*> & st) {
    while(root) {
        st.push(root);
        root = root->left;
    }
}

void pushRightUtillNull(TreeNode* root, std::stack<TreeNode*> & st) {
    while(root) {
        st.push(root);
        root = root->right;
    }
}

bool findTarget(TreeNode* root, int k) {
    std::stack<TreeNode*> frontSt, backSt;
    pushLeftUtillNull(root, frontSt);
    pushRightUtillNull(root, backSt);
    while(!frontSt.empty() && !backSt.empty()) {
        TreeNode* front = frontSt.top();
        TreeNode* back  = backSt.top();
        if(front == back) {
            return false;
        }

        int sum = front->val + back->val;
        if(sum == k) {
            return true;
        }else if(sum < k) {
            frontSt.pop();
            pushLeftUtillNull(front->right, frontSt);
        }else {
            backSt.pop();
            pushRightUtillNull(back->left, backSt);
        }
    }

    return false;
}