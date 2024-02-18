#include "637.AverageofLevelsinBinaryTree.h"
#include "treecomm.h"
#include <queue>

vector<double> averageOfLevels(TreeNode* root) {
    if(root == nullptr) {
        return {};
    }    

    vector<double> ans;
    queue<TreeNode* > que;
    que.push(root);
    int size = 1;
    while(!que.empty()) {
        double sum = 0;
        for(int i = 0; i < size; ++i) {
            TreeNode * node = que.front(); que.pop();
            sum += node->val;
            if(node->left) {
                que.push(node->left);
            }
            if(node->right) {
                que.push(node->right);
            }
        }
        ans.push_back(sum / size);
        size = que.size();
    }
    return ans;
}


vector<double> averageOfLevels1(TreeNode* root) {
    vector<double> vecAns;
    if(root == nullptr) {
        return vecAns;
    }

    std::queue<TreeNode*> que; que.push(root);
    while(!que.empty()) {
        int iSize = que.size();
        double iSum = 0;
        for(int i = 0; i < iSize; ++i) {
            TreeNode* pNode = que.front(); que.pop();
            iSum += pNode->val;
            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        }
        vecAns.push_back(iSum / iSize);
    }

    return vecAns;
}