#include "889.ConstructBinaryTreefromPreorderandPostorderTraversal.h"

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int preb, int pree, int postb, int poste) {
    if(preb < 0 || pree < preb || pree >= preorder.size() || postb < 0 || poste < postb || poste >= postorder.size()) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[preb]);
    int leftlen = 0;
    if(preb < pree) {
        int left = preorder[preb + 1];
        if(postorder[poste - 1] != left) {
            int post = postb;
            while(post < poste && postorder[post] != left) {
                ++leftlen;
                ++post;
            }
            leftlen += 1;
        }
    }

    node->left = constructFromPrePost(preorder, postorder, preb + 1, preb + leftlen, postb, postb + leftlen - 1);
    node->right= constructFromPrePost(preorder, postorder, preb + leftlen + 1, pree, postb + leftlen, poste - 1);
    return node;
}


TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    if(preorder.empty() || postorder.empty() || preorder.size() != postorder.size()) {
        return nullptr;
    }

    return constructFromPrePost(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
}