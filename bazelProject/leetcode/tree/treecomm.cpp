#include "treecomm.h"
#include <iostream>

void TraverseTreePre(TreeNode * root)
{
    if(!root) return;
    printf("%d,", root->val);
    TraverseTreePre(root->left);
    TraverseTreePre(root->right);
}

void TraverseTreePre(TreeNode * root, std::string & res)
{
    if(!root) return;
    if(res.size()) 
    {
        res += " ";
        res += std::to_string(root->val);
    }else{
        res = std::to_string(root->val);
    }
    TraverseTreePre(root->left, res);
    TraverseTreePre(root->right, res);
}

void TraverseTreeMid(TreeNode * root)
{
    if(!root) return;
    TraverseTreeMid(root->left);
    printf("%d, ", root->val);
    TraverseTreeMid(root->right);
}

void TraverseTreeMid(TreeNode * root, std::string & res)
{
    if(!root) return;
    TraverseTreeMid(root->left, res);
    if(res.size()) 
    {
        res += " ";
        res += std::to_string(root->val);
    }else{
        res = std::to_string(root->val);
    }
    TraverseTreeMid(root->right, res);
}


void TraverseTreePost(TreeNode * root)
{
    if(!root) return;
    TraverseTreePre(root->left);
    TraverseTreePre(root->right);
    printf("%d,", root->val);
}


void TraverseTreePost(TreeNode * root, std::string & res)
{
    if(!root) return;
    TraverseTreePost(root->left, res);
    TraverseTreePost(root->right, res);
    if(res.size()) 
    {
        res += " ";
        res += std::to_string(root->val);
    }else{
        res = std::to_string(root->val);
    }
}

void TraverseTreePreNoRecursion(TreeNode * root)
{
    if(!root) return;
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

void TraverseTreeLevelDebug(TreeNode * root)
{
    if(!root) return;
    std::queue<TreeNode *> que;
    que.push(root);
    while(que.size())
    {
        int64_t size = que.size();
        while(size--)
        {
            TreeNode * pNode = que.front();
            que.pop();
            printf("%d, addr %p, left %p, right %p, ", pNode->val, pNode, pNode->left, pNode->right);
            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        }
        printf("\n");
    }
}



void FreeTree(TreeNode * root)
{
    if(!root) return;
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
}


TreeNode * CreateTree(const std::vector<int> &pre, const std::vector<int> mid, size_t pre_b, size_t pre_e, size_t mid_b, size_t mid_e)
{
    if(pre_b > pre_e || mid_b > mid_e || 
       pre_b >= pre.size() || mid_b >= mid.size() || 
       pre_e < 0 || mid_e < 0) {
        return nullptr;
    }

    TreeNode * root = new TreeNode(pre[pre_b]);
    size_t mid_idx = mid_b, len = 0;
    while(mid_idx <= mid_e && pre[pre_b] != mid[mid_idx]) 
    {
        ++mid_idx;
        ++len;
    }
    root->left = CreateTree(pre, mid, pre_b + 1, pre_b + len, mid_b, mid_idx - 1);
    root->right = CreateTree(pre, mid, pre_b + len + 1, pre_e, mid_idx + 1, mid_e);

    return root;
}


TreeNode * CreateTree(const std::vector<int> pre, const std::vector<int> mid)
{
    if(pre.size() != mid.size() || pre.size() == 0){
        return nullptr;
    }

    return CreateTree(pre, mid, 0, pre.size() - 1, 0, mid.size() - 1);
}
