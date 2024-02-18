#include "236.LowestCommonAncestorofaBinaryTree.h"
#include "treecomm.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) {
        return root;
    }
    return left ? left : right;
}


TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* pLeft = lowestCommonAncestor1(root->left, p, q);
    TreeNode* pRight = lowestCommonAncestor1(root->right, p, q);
    if(pLeft && pRight) {
        return root;
    }

    return pLeft ? pLeft : pRight;
}