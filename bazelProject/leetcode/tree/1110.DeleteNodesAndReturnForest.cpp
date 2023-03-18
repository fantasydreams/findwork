#include "1110.DeleteNodesAndReturnForest.h"
#include <unordered_set>
#include <queue>

TreeNode * delNodes(TreeNode* root, const std::unordered_set<int>& set, std::vector<TreeNode* > &ans) {
    if(root == nullptr) {
        return root;
    }

    root->left = delNodes(root->left, set, ans);
    root->right = delNodes(root->right, set, ans);
    if(set.count(root->val)) {
        if(root->left) {
            ans.push_back(root->left);
        }
        if(root->right) {
            ans.push_back(root->right);
        }
        delete root;
        root = nullptr;
    }
    return root;
}

std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {
    std::vector<TreeNode* > ans;
    std::unordered_set<int> set(to_delete.begin(), to_delete.end());
    
    if(delNodes(root, set, ans)) {
        ans.push_back(root);
    }
    return ans;
}