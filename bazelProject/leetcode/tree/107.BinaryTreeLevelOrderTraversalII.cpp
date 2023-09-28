#include "107.BinaryTreeLevelOrderTraversalII.h"
#include <algorithm>
#include <queue>

vector<vector<int> > levelOrderBottom(TreeNode* root) {
    vector<vector<int> > ans;
    if(root == nullptr) {
        return ans;
    }

    std::queue<TreeNode*> que; que.push(root);
    while(!que.empty()) {
        int size = que.size();
        std::vector<int> levelAns;
        for(int i = 0; i < size; ++i) {
            TreeNode* pNode = que.front(); que.pop();
            levelAns.push_back(pNode->val);
            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        }

        ans.emplace_back(std::move(levelAns));
    }

    std::reverse(ans.begin(), ans.end());
    return ans;
}