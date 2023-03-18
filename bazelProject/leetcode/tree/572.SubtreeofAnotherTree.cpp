#include "572.SubtreeofAnotherTree.h"


bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    bool isSub = isTreeValEqual(root, subRoot);
    if(isSub) {
        return true;
    }
    if(root) {
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
    return false;
}