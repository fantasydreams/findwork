#include "617.MergeTwoBinaryTrees.h"

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr && root2 == nullptr) {
        return nullptr;
    }

    int sum = (root1 ? root1 -> val : 0) + (root2 ? root2 -> val : 0);
    TreeNode * node = new TreeNode(sum);
    node->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2 -> left : nullptr);
    node->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2 -> right : nullptr);
    return node;
}