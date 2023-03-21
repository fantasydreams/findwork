#include "105.ConstructBinaryTreefromPreorderandInorderTraversal.h"

TreeNode* buildTreePreMid(const vector<int>& preorder, int preS, int preE, const vector<int>& inorder, int inS, int inE) {
    if(preS <0 || preE >= preorder.size() ||  preE < preS || inS < 0 || inE >= inorder.size() || inE < inS) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[preS]);
    int rootPosIn = inS;
    while(rootPosIn < inE && preorder[preS] != inorder[rootPosIn]) {
        ++rootPosIn;
    }

    root->left = buildTreePreMid(preorder, preS + 1, preS + rootPosIn - inS, inorder, inS, rootPosIn - 1);
    root->right = buildTreePreMid(preorder, preS + rootPosIn - inS + 1, preE, inorder, rootPosIn + 1, inE);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) {
        return nullptr;
    }

    return buildTreePreMid(preorder, 0, preorder.size()- 1, inorder, 0, inorder.size() - 1);
}