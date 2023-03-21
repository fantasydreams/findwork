#include "226.InvertBinaryTree.h"
#include <stack>


TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) {
        return root;
    }

    invertTree(root->left);
    invertTree(root->right);
    TreeNode * tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}

void PushTaskLeftPathUntilNull(TreeNode * root, std::stack<TreeNode *> & stack);
TreeNode* invertTreeNoRecursion(TreeNode * root)
{
    if(!root){
        return root;
    } 

    TreeNode * pre = nullptr, *tmp;
    std::stack<TreeNode *> stack;
    PushTaskLeftPathUntilNull(root, stack);
    while(!stack.empty())
    {
        TreeNode * pTmp = stack.top();
        if(pTmp->right == pre || pTmp->right == nullptr)
        {
            stack.pop();
            pre = pTmp;
            tmp = pTmp->left;
            pTmp->left =  pTmp->right;
            pTmp->right = tmp;
        }else{
            PushTaskLeftPathUntilNull(pTmp->right, stack);
        }
    }

    return root;
}