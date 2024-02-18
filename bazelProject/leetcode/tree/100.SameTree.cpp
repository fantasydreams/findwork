#include "100.SameTree.h"

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) {
        return true;
    }
    
    if((p && !q) || (!p && q) || (p->val != q->val)) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
}


bool isSameTree1(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr) {
        return true;
    }
    if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) || (p->val != q->val)) {
        return false;
    }

    return isSameTree1(p->left, q->left) && isSameTree1(p->right, q->right);
}