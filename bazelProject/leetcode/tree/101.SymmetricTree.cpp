#include "101.SymmetricTree.h"
#include <queue>

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if(left == nullptr && right == nullptr) {
        return true;
    }else if((left && right == nullptr) || (right && left == nullptr)){
        return false;
    }else {
        if(left->val != right -> val) {
            return false;
        }
        return (isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
    }
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }

    return isSymmetric(root->left, root->right);
}

bool isSymmetricIterator(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }

    std::queue<TreeNode *> qleft, qright;
    qleft.push(root->left);
    qright.push(root->right);
    while(!qleft.empty() && !qright.empty()) {
        TreeNode * left = qleft.front(); qleft.pop();
        TreeNode * right = qright.front(); qright.pop();
        if(left == nullptr && right == nullptr) {
            continue;
        }
        if((left && right == nullptr) || (right && left == nullptr) || (left->val != right->val)) {
            return false;
        }
        
        qleft.push(left->right);
        qleft.push(left->left);
        qright.push(right->left);
        qright.push(right->right);
    }

    return qleft.empty() && qright.empty();
}