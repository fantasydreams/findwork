#include "543.DiameterofBinaryTree.h"

int getDiameter(TreeNode * root, int & diamster) {
    if(root == nullptr) {
        diamster = 0;
        return 0;
    }

    int tmpdia1 = 0, tmpdia2 = 0;
    int left = getDiameter(root->left, tmpdia1);
    int right = getDiameter(root->right, tmpdia2);
    diamster = std::max(diamster, left + right);
    diamster = std::max(diamster, tmpdia1);
    diamster = std::max(diamster, tmpdia2);
    return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diamster = 0;
    getDiameter(root, diamster);
    return diamster;
}