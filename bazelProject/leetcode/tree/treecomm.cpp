#include "treecomm.h"
#include <iostream>

void PushTaskLeftPathUntilNull(TreeNode * root, std::stack<TreeNode *> & stack);

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

void TraverseTreePostNoRecursion(TreeNode * root, std::string & res)
{
    if(!root){
        return;
    } 

    TreeNode * pre = nullptr;
    std::stack<TreeNode *> stack;
    PushTaskLeftPathUntilNull(root, stack);
    while(stack.size())
    {
        TreeNode * pTmp = stack.top();
        if(pTmp->right == pre || pTmp->right == nullptr)
        {
            stack.pop();
            if(res.size() == 0){
                res += std::to_string(pTmp->val);
            }else
            {
                res += " ";
                res += std::to_string(pTmp->val);
            }
            pre = pTmp;
        }else{
            PushTaskLeftPathUntilNull(pTmp->right, stack);
        }
    }
}


void PushTaskLeftPathUntilNull(TreeNode * root, std::stack<TreeNode *> & stack)
{
    while(root){
        stack.push(root);
        root = root->left;
    }
}

void TraverseTreeMidNoRecursion(TreeNode * root, std::string & res)
{
    if(!root) return;
    std::stack<TreeNode *> stack;
    PushTaskLeftPathUntilNull(root, stack);

    while(stack.size())
    {
        TreeNode * pNode = stack.top();
        stack.pop();
        if(res.size() == 0){
            res += std::to_string(pNode->val);
        }else{
            res += " ";
            res += std::to_string(pNode->val);
        }
        if(pNode->right){
            PushTaskLeftPathUntilNull(pNode->right, stack);
        }
    }
}

void TraverseTreeMidNoRecursion(TreeNode * root, std::vector<int> & res)
{
    if(!root) return;
    std::stack<TreeNode *> stack;
    PushTaskLeftPathUntilNull(root, stack);

    while(stack.size())
    {
        TreeNode * pNode = stack.top();
        stack.pop();
        res.push_back(pNode->val);
        if(pNode->right){
            PushTaskLeftPathUntilNull(pNode->right, stack);
        }
    }
}

void TraverseTreePreNoRecursion(TreeNode * root)
{
    if(!root) return;
    std::stack<TreeNode *> st;
    st.push(root);

    while(st.size())
    {
        TreeNode * pNode = st.top();
        st.pop();
        printf("%d,", pNode->val);
        if(pNode->right) {
            st.push(pNode->right);
        }
        if(pNode->left) {
            st.push(pNode->left);
        }
    }
}


void TraverseTreePreNoRecursion(TreeNode * root, std::string & res)
{
    if(!root) return;
    std::stack<TreeNode *> stack;
    stack.push(root);

    while(stack.size())
    {
        TreeNode * pNode = stack.top();
        stack.pop();
        if(res.size() == 0){
            res = std::to_string(pNode->val);
        }else
        {
            res += " ";
            res += std::to_string(pNode->val);
        }
        if(pNode->right) {
            stack.push(pNode->right);
        }
        if(pNode->left) {
            stack.push(pNode->left);
        }
    }
}

void TraverseTreePreNoRecursion(TreeNode * root, std::vector<int> & res)
{
    if(!root) return;
    std::stack<TreeNode *> stack;
    stack.push(root);

    while(stack.size())
    {
        TreeNode * pNode = stack.top();
        stack.pop();
        res.push_back(pNode->val);
        if(pNode->right) {
            stack.push(pNode->right);
        }
        if(pNode->left) {
            stack.push(pNode->left);
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


TreeNode * CreateTreePreMid(const std::vector<int> & pre, const std::vector<int> & mid, int64_t pre_b, int64_t pre_e, int64_t mid_b, int64_t mid_e)
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
    root->left = CreateTreePreMid(pre, mid, pre_b + 1, pre_b + len, mid_b, mid_idx - 1);
    root->right = CreateTreePreMid(pre, mid, pre_b + len + 1, pre_e, mid_idx + 1, mid_e);

    return root;
}


TreeNode * CreateTreePreMid(const std::vector<int> & pre, const std::vector<int> & mid)
{
    if(pre.size() != mid.size() || pre.size() == 0){
        return nullptr;
    }

    return CreateTreePreMid(pre, mid, 0, pre.size() - 1, 0, mid.size() - 1);
}

TreeNode * CreateTreeMidPost(const std::vector<int> & mid, const std::vector<int> & post, int64_t mid_b, int64_t mid_e, int64_t post_b, int64_t post_e)
{
    if(mid_b > mid_e || post_b > post_e ||
       mid_b >= mid.size() || mid_e < 0 ||
       post_b >= post.size() || post_e < 0 ){
           return nullptr;
    }

    TreeNode * root = new TreeNode(post[post_e]);
    uint64_t m_idx = mid_b;
    while(m_idx <= mid_e && mid[m_idx] != post[post_e]){
        ++m_idx;
    }

    root->left  = CreateTreeMidPost(mid, post, mid_b, m_idx - 1, post_b, post_b + m_idx - mid_b - 1);
    root->right = CreateTreeMidPost(mid, post, m_idx + 1, mid_e, post_b + m_idx - mid_b, post_e - 1);
    return root;
}

TreeNode * CreateTreeMidPost(const std::vector<int> & mid, const std::vector<int> & post)
{
    if(mid.size() != post.size() || post.size() == 0){
        return nullptr;
    }
    return CreateTreeMidPost(mid, post, 0, mid.size() - 1, 0, post.size() - 1);
}

bool isTreeValEqual(TreeNode* a, TreeNode* b) {
    if(a == nullptr && b == nullptr) {
        return true;
    }else if((a == nullptr && b != nullptr) || (b == nullptr && a != nullptr) || (a->val != b->val)) {
        return false;
    }else {
        return isTreeValEqual(a->left, b->left) && isTreeValEqual(a->right, b->right);
    }
    return false;
}