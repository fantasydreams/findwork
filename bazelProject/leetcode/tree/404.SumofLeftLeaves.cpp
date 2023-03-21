#include "404.SumofLeftLeaves.h"
#include <queue>

int sumOfLeftLeaves(TreeNode* root) {
    if(!root) {
        return 0;
    }

    int64_t sum = 0;
    std::queue<std::pair<TreeNode *, int>> que;
    que.push({root, 0});
    while(!que.empty()) {
        auto [node, type] = que.front();
        que.pop();
        if(node->left) {
            que.push({node->left, 1});
        }
        if(node->right) {
            que.push({node->right, 0});
        }
        if(!node->left && !node->right && type == 1) {
            sum += node->val;
        }
    }

    return sum;
}