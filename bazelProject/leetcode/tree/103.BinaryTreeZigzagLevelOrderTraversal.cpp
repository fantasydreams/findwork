#include "103.BinaryTreeZigzagLevelOrderTraversal.h"
#include "treecomm.h"
#include <vector>
#include <queue>

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > ans;
    if(root == nullptr) {
        return ans;
    }

    std::queue<TreeNode*> que;
    que.push(root);
    bool flag = false;
    while(!que.empty()) {
        int size = que.size();
        std::vector<int> levelRecord;
        while(size) {
            TreeNode* pNode = que.front(); que.pop();
            levelRecord.push_back(pNode->val);
            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        
            --size;   
        }
        
        if(flag) {
            std::reverse(levelRecord.begin(), levelRecord.end());
        }
        flag = !flag;
        ans.emplace_back(std::move(levelRecord));
    }

    return ans;
}


vector<vector<int> > zigzagLevelOrder1(TreeNode* root)  {
    vector<vector<int> > vecAns;
    if(root == nullptr) {
        return vecAns;
    }

    bool bFlag = false;
    std::queue<TreeNode*> que;que.push(root);
    while(!que.empty()) {
        int iSize = que.size();
        vector<int> vecLevel;
        while(iSize--) {
            TreeNode* pNode = que.front(); que.pop();
            vecLevel.push_back(pNode->val);
            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        }
        if(bFlag) {
            std::reverse(vecLevel.begin(), vecLevel.end());
        }
        bFlag = !bFlag;
        vecAns.emplace_back(vecLevel);
    }
    return vecAns;
}