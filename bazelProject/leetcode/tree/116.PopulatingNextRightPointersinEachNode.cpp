#include "116.PopulatingNextRightPointersinEachNode.h"
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
Node* connect(Node* root)
{
    if(!root) return root;
    if(root->left) {
        root->left->next = root->right;
    }
    if(root->next && root->right){
        root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);

    return root;
}