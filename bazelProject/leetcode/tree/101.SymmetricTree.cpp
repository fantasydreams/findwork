#include "101.SymmetricTree.h"
#include "treecomm.h"
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


bool isSymmetric1(TreeNode* left, TreeNode* right) {
        if(!left && !right)  {
            return true;
        }
        if(left && !right || !left && right || left->val != right->val) {
            return false;
        }

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

bool isSymmetric1(TreeNode* root) {
    if(!root) {
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


bool isSymmetric2(TreeNode* pLeft, TreeNode* pRight) {
    if(pLeft == nullptr && pRight == nullptr) {
        return true;
    }
    if((pLeft == nullptr && pRight != nullptr) || (pLeft != nullptr && pRight == nullptr) || (pLeft->val != pRight->val)) {
        return false;
    }
    return isSymmetric2(pLeft->left, pRight->right) && isSymmetric2(pLeft->right, pRight->left);
}

bool isSymmetric2(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }

    return isSymmetric2(root->left, root->right);
}

bool isSymmetricNoRecursor(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }

    std::queue<TreeNode*> queLeft, queRight;
    queLeft.push(root->left); queRight.push(root->right);
    while(!queLeft.empty() && !queRight.empty()) {
        TreeNode* pLeft = queLeft.front();queLeft.pop();
        TreeNode* pRight = queRight.front();queRight.pop();
        if(pLeft == nullptr && pRight == nullptr) {
            continue;
        }
        if(pLeft && !pRight || !pLeft && pRight || pLeft->val != pRight->val) {
            return false;
        }

        queLeft.push(pLeft->left);
        queLeft.push(pLeft->right);
        queRight.push(pRight->right);
        queRight.push(pRight->left);
    }

    return queLeft.empty() && queRight.empty();
}
