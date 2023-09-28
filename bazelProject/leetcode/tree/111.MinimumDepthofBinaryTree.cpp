#include "111.MinimumDepthofBinaryTree.h"
#include "treecomm.h"
#include <queue>

int minDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int ans = 0;
    std::queue<TreeNode*> que;que.push(root);
    while(!que.empty()) {
        ++ans;
        int size = que.size();
        while(size) {
            TreeNode* pNode = que.front();que.pop();
            if(pNode->left || pNode->right) {
                if(pNode->left) {
                    que.push(pNode->left);
                }
                if(pNode->right) {
                    que.push(pNode->right);
                }
            }else {
                return ans;
            }
            --size;
        }
    }

    return ans;
}