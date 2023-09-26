#include "103.BinaryTreeZigzagLevelOrderTraversal.h"
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