#include "99.RecoverBinarySearchTree.h"

void TreeMidReverse(TreeNode* root, TreeNode* &pErr1, TreeNode* &pErr2, TreeNode * &pPre) {
    if(!root) {
        return;
    }

    TreeMidReverse(root->left, pErr1, pErr2, pPre);
    if(pPre && pPre->val > root->val) {
        if(!pErr1) {
            pErr1 = pPre;
            pErr2 = root;
        }else {
            pErr2 = root;
        }
    }

    pPre = root;
    TreeMidReverse(root->right, pErr1, pErr2, pPre);
}

void recoverTree(TreeNode* root) {
    if(!root) {
        return;
    }

    TreeNode* pErr1 = nullptr, *pErr2 = nullptr, *pPre = nullptr;
    TreeMidReverse(root, pErr1, pErr2, pPre);
    if(pErr1 && pErr2) {
        int tmp = pErr1->val;
        pErr1->val = pErr2->val;
        pErr2->val = tmp;
    }
}