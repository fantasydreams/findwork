#include "637.AverageofLevelsinBinaryTree.h"
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