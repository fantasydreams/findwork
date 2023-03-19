#include "106.ConstructBinaryTreefromInorderandPostorderTraversal.h"

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inb, int ine, int postb, int poste) {
    if(inb < 0 || ine < inb || ine >= inorder.size() || postb < 0 || poste < postb || poste >= postorder.size()) {
        return nullptr;
    }

    TreeNode * root = new TreeNode(postorder[poste]);
    int rootPost = inb;
    while(rootPost < ine && postorder[poste] != inorder[rootPost]) {
        ++rootPost;
    }

    root->left = buildTree(inorder, postorder, inb, rootPost - 1, postb, postb + rootPost - inb - 1);
    root->right = buildTree(inorder, postorder, rootPost + 1, ine, postb + rootPost - inb, poste - 1);
    return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
        return nullptr;
    }

    return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}