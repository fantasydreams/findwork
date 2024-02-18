#include "222.CountCompleteTreeNodes.h"
#include "treecomm.h"
#include <queue>


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


int countNodesON(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    std::queue<TreeNode*> que; que.push(root); 
    int ans = 0;
    while(!que.empty()) {
        ans += que.size();
        int size = que.size();
        while(size--) {
            TreeNode* node = que.front(); que.pop();
            if(node->left) {
                que.push(node->left);
            }
            if(node->right) {
                que.push(node->right);
            }
        }
    }

    return ans;
}


int countNodesAttr(TreeNode* root) {
    if(!root) {
        return 0;
    }

    int leftLevel = 0;
    TreeNode * pLeft = root;
    while(pLeft) {
        ++leftLevel;
        pLeft = pLeft->left;
    }

    int RightLevel = 0;
    TreeNode* pRifht = root;
    while(pRifht) {
        ++RightLevel;
        pRifht = pRifht->right;
    }

    if(leftLevel == RightLevel) {
        return (2 << (leftLevel - 1)) - 1;
    }

    return countNodesAttr(root->left) + countNodesAttr(root->right) + 1;

}

int countNodesAttr1(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int iLevelLeft = 0, iLevelRight = 0;
    TreeNode* pTmp = root;
    while(pTmp) {
        ++iLevelLeft;
        pTmp = pTmp->left;
    }

    pTmp = root;
    while(pTmp) {
        ++iLevelRight;
        pTmp = pTmp->right;
    }

    if(iLevelLeft == iLevelRight) {
        return (2 << (iLevelLeft - 1)) - 1;
    }

    return countNodesAttr1(root->left) + countNodesAttr1(root->right) + 1;
}