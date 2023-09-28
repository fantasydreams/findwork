#include "116.PopulatingNextRightPointersinEachNode.h"
#include "treecomm.h"
#include <cstddef>
#include <queue>


//层次遍历
Node* connect(Node* root)
{
    if(!root) return root;
    std::queue<Node *> que;
    que.push(root);
    int size = 1;
    while(que.size())
    {
        while(size--)
        {
            Node * node = que.front();
            que.pop();
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }

            if(size != 0){
                node->next = que.front();
            }else{
                node->next = nullptr;
            }
        }
        size = que.size();
    }

    return root;
}

//剪枝
Node* connect2(Node* root)
{
    if(!root) return root;
    if(root->left) {
        root->left->next = root->right;
    }
    if(root->next && root->right){
        root->right->next = root->next->left;
    }

    connect2(root->left);
    connect2(root->right);

    return root;
}


// letcode 117也能用这个方法
Node* connect3(Node* root) {
    if(!root) {
        return nullptr;
    }

    std::queue<Node*> que;que.push(root);
    while(!que.empty()) {
        int size = que.size();
        Node* pPre = nullptr;
        while(size) {
            Node* pNode = que.front(); que.pop();
            if(pPre) {
                pPre->next = pNode;
            }

            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
            pPre = pNode;
            --size;
        }
        pPre->next = nullptr;
    }

    return root;
}