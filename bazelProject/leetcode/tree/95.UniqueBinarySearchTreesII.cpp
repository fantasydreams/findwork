
#include "95.UniqueBinarySearchTreesII.h"
#include <vector>

std::vector<TreeNode*> bt(int start, int end) {
    if(start > end) {
        return {nullptr};
    }

    std::vector<TreeNode*> ans;
    for(int k = start; k <= end; ++k) {
        std::vector<TreeNode*> Left = bt(start, k - 1);
        std::vector<TreeNode*> right = bt(k + 1, end);
        for(auto leftTree : Left) {
            for(auto rightTree : right) {
                TreeNode* pNode = new TreeNode(k);
                pNode->left = leftTree;
                pNode->right = rightTree;
                ans.push_back(pNode);
            }
        }
    }

    return ans;
}

vector<TreeNode*> generateTrees(int n) {
    return bt(1, n);
}