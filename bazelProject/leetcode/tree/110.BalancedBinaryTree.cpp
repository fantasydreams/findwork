#include "110.BalancedBinaryTree.h"
#include <cmath>
#include <cstdlib>

bool isBalanced(TreeNode * root, int & depth) {
    if(!root) {
        depth = 0;
        return true;
    }

    int left = 0, right = 0;
    if(isBalanced(root->left, left) == false) {
        return false;
    }
    if(isBalanced(root->right, right) == false) {
        return false;
    }
    
    if(abs(left - right) > 1) {
        return false;
    }

    depth = std::max(left, right) + 1;
    return true;
}

bool isBalanced(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }

    int depth = 0;
    return isBalanced(root, depth);
}

bool isBalanced1(TreeNode *root, int& iDepth) {
    if(root == nullptr) {
        iDepth = 0;
        return true;
    }    

    int leftD = 0, rightD = 0;
    if(isBalanced1(root->left, leftD) == false) {
        return false;
    }
    if(isBalanced1(root->right, rightD) == false) {
        return false;
    }

    if(abs(leftD - rightD) > 1) {
        return false;
    }

    iDepth = std::max(leftD, rightD) + 1;
    return true;
}

bool isBalanced1(TreeNode *root) {
    int depth = 0;
    return isBalanced1(root, depth);
}