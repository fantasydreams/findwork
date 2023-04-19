#include "662.MaximumWidthofBinaryTree.h"
#include <queue>

int widthOfBinaryTree(TreeNode* root) {
    if(!root) {
        return 0;
    }

    std::queue<TreeNode*> que;
    que.push(root);

    int ans = 1;
    int size = 1;
    bool notnull = true;
    while(!que.empty() && notnull) {
        int start = -1;
        notnull = false;
        for(int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if(node) {
                notnull = true;
                que.push(node->left);
                que.push(node->right);
                if(start == -1) {
                    start = i;
                }
                ans = std::max(i + 1 - start, ans);
            }else {
                que.push(nullptr);
                que.push(nullptr);
            }
        }

        size = que.size();
    }

    return ans;
}

int widthOfBinaryTree1(TreeNode* root) {
    if(!root) {
        return 0;
    }

    std::queue<std::pair<TreeNode*, int>> que;
    que.push({root, 0});

    int ans = 1;
    int size = 1;
    while(!que.empty()) {
        int end = que.back().second;
        int start =  que.front().second;
        ans = std::max(end - start + 1, ans);

        for(int i = 0; i < size; ++i) {
            const auto [node, curIdx] = que.front(); que.pop();
            int Idx = curIdx - start;

            if(node->left) {
                que.push({node->left, (int64_t)Idx * 2 + 1});
            }
            if(node->right) {
                que.push({node->right, (int64_t)(Idx + 1) * 2});
            }
        }
        size = que.size();
    }

    return ans;
}