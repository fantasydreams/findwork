#include "110.BalancedBinaryTree.h"
#include <cmath>

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