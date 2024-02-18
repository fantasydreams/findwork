#include "106.ConstructBinaryTreefromInorderandPostorderTraversal.h"
#include "treecomm.h"
#include <cstddef>
#include <iterator>
#include <unordered_map>
#include <iostream>

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

TreeNode* buildTreeHash(vector<int>& inorder, vector<int>& postorder, int inb, int ine, int postb, int poste, const std::unordered_map<int, int>& oDict) {
    if(inb > ine || inb < 0 || ine >= inorder.size() || postb < 0 || postb > poste || poste >= postorder.size()) {
        return nullptr;
    }

    int iLoc = oDict.at(postorder[poste]);
    TreeNode* root = new TreeNode(postorder[poste]);
    // std::cout << postorder[poste] << " " << iLoc << std::endl;    
    root->left = buildTreeHash(inorder, postorder, inb, iLoc - 1, postb, postb + iLoc - inb - 1, oDict);
    root->right = buildTreeHash(inorder, postorder, iLoc + 1, ine, postb + iLoc - inb, poste - 1, oDict);
    return root;
}

TreeNode* buildTreeHash(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() == 0 || inorder.size() != postorder.size()) {
        return nullptr;
    }

    std::unordered_map<int, int> hashMap;
    for(int i = 0; i < inorder.size(); ++i) {
        auto oPair = hashMap.insert({inorder[i], i});
        if(oPair.second == false) {
            return nullptr;
        }
    }

    return buildTreeHash(inorder, postorder, 0, inorder.size() - 1, 0, inorder.size() - 1, hashMap);
}

TreeNode* buildTreeHash1(const vector<int>& vecInorder, int iInB, int iInE, const vector<int>& vecPostorder, int iPostB, int iPostE, const std::unordered_map<int, int>& oDict) {
    if(iInB > iInE || iInB >= vecInorder.size() || iInE < 0 || iPostB > iPostE || iPostB >= vecPostorder.size() || iPostE < 0) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(vecPostorder[iPostE]);
    int iLoc = oDict.at(vecPostorder[iPostE]);
    root->left = buildTreeHash1(vecInorder, iInB, iLoc - 1, vecPostorder, iPostB, iPostB + iLoc - iInB - 1, oDict);
    root->right = buildTreeHash1(vecInorder, iLoc + 1, iInE, vecPostorder, iPostB + iLoc - iInB, iPostE - 1, oDict);
    return root;
}

TreeNode* buildTreeHash1(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty() || inorder.size() != postorder.size()) {
        return nullptr;
    }

    std::unordered_map<int, int> hashMap;
    for(int i = 0; i < inorder.size(); ++i) {
        auto oPair = hashMap.insert({inorder[i], i});
        if(oPair.second == false) {
            return nullptr;
        }
    }

    return buildTreeHash1(inorder, 0, inorder.size() - 1, postorder, 0 ,postorder.size() -1, hashMap);
}
