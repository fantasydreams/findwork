#include "543.DiameterofBinaryTree.h"

int getDiameter(TreeNode * root, int & diamster) {
    if(root == nullptr) {
        return 0;
    }

    int left = getDiameter(root->left, diamster);
    int right = getDiameter(root->right, diamster);
    diamster = std::max(diamster, left + right);
    return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diamster = 0;
    getDiameter(root, diamster);
    return diamster;
}