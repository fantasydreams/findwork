#include "treecomm.h"

void TraverseTreePre(TreeNode * root)
{
    if(!root) return;
    printf("%d,", root->val);
    TraverseTreePre(root->left);
    TraverseTreePre(root->right);
}

void TraverseTreeMid(TreeNode * root)
{
    if(!root) return;
    TraverseTreePre(root->left);
    printf("%d,", root->val);
    TraverseTreePre(root->right);
}


void TraverseTreePost(TreeNode * root)
{
    if(!root) return;
    TraverseTreePre(root->left);
    TraverseTreePre(root->right);
    printf("%d,", root->val);
}


void TraverseTreePreNoRecursion(TreeNode * root)
{
    if(!root) return;
    TreeNode * tmpPtr = root;
    std::queue<TreeNode *> que;
    que.push(root);

    while(que.size())
    {
        TreeNode * pNode = que.front();
        que.pop();
        printf("%d,", pNode->val);
        if(pNode->right) {
            que.push(pNode->right);
        }
        if(pNode->left) {
            que.push(pNode->left);
        }
    }
}