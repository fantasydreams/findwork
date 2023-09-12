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