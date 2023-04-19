#include "222.CountCompleteTreeNodes.h"


int countNodes(TreeNode* root) {
    if(!root) {
        return 0;
    }

    int leftLevel = 0, rightLevel = 0;
    TreeNode* tmp = root;
    while(tmp) {
        ++leftLevel;
        tmp = tmp->left;
    }
    
    tmp = root;
    while(tmp) {
        ++rightLevel;
        tmp = tmp->right;
    }
    
    if(leftLevel == rightLevel) {
        return (1 << leftLevel) - 1;
    }else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}