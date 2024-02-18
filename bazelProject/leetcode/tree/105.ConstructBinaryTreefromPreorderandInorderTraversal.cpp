#include "105.ConstructBinaryTreefromPreorderandInorderTraversal.h"
#include "treecomm.h"
#include <ostream>
#include <unordered_map>
#include <iostream>

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


TreeNode* buildTreePreMid1(const std::vector<int>& preorder, int preS, int preE, const std::vector<int>& inorder, int inS, int inE) {
    if(preS < 0 || preE >= preorder.size() || preS > preE || inS < 0 || inE >= inorder.size() || inS > inE) {
        return nullptr;
    }

    // 找到先序中第一个元素在中序中的位置，然后一分为二
    TreeNode* root = new TreeNode(preorder[preS]);
    int iLoc = inS;
    while(iLoc <= inE && preorder[preS] !=inorder[iLoc]) {
        ++iLoc;
    }

    root->left = buildTreePreMid1(preorder, preS + 1, preS + iLoc - inS, inorder, inS, iLoc - 1);
    root->right = buildTreePreMid1(preorder, preS + iLoc - inS + 1, preE, inorder, iLoc + 1, inE);

    return root;
}

TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) { // 2023/9/27
    if(preorder.size() == 0 || preorder.size() != inorder.size()) {
        return nullptr;
    }    

    return buildTreePreMid1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}


TreeNode* buildTreeUserDict(const std::vector<int>& preorder, int preS, int preE, const std::vector<int>& inorder, int inS, int inE, const std::unordered_map<int, int>& oDict) {
    if(preS < 0 || preE >= preorder.size() || preS > preE || inS < 0 || inE >= inorder.size() || inS > inE) {
        return nullptr;
    }

    int iLoc = oDict.at(preorder[preS]);
    // std::cout << preorder[preS] << " " << iLoc << std::endl;
    TreeNode* root = new TreeNode(preorder[preS]);

    root->left = buildTreeUserDict(preorder, preS + 1, preS + iLoc - inS, inorder, inS, iLoc - 1, oDict);
    root->right = buildTreeUserDict(preorder, preS + iLoc - inS + 1, preE, inorder, iLoc + 1, inE, oDict);
    return root;
}


TreeNode* buildTreeHash(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0 || preorder.size() != inorder.size()) {
        return nullptr;
    } 

    std::unordered_map<int, int> hashMap;
    for(int i = 0; i < inorder.size(); ++i) {
        auto oPair = hashMap.insert({inorder[i], i});
        if(oPair.second == false) {
            return nullptr;
        }
    }

    // for(auto & oPair : hashMap) {
    //     std::cout << oPair.first << " " << oPair.second << std::endl;
    // }

    return buildTreeUserDict(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, hashMap);
}


TreeNode* buildTreeUserDict1(const std::vector<int>& preorder, int iPreL, int iPreR, const std::vector<int>& inorder, int iMidL, int iMidR, std::unordered_map<int, int>& hashMap) {
    if(iPreL > iPreR || iPreL>= preorder.size() || iPreR < 0 || iMidL > iMidR || iMidL >= inorder.size() || iMidR < 0) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[iPreL]);
    int iLoc = hashMap.at(preorder[iPreL]);
    root->left = buildTreeUserDict1(preorder, iPreL + 1, iPreL + iLoc - iMidL, inorder, iMidL, iLoc - 1, hashMap);
    root->right = buildTreeUserDict1(preorder, iPreL + iLoc - iMidL + 1, iPreR, inorder, iLoc + 1, iMidR, hashMap);
    return root;
}


TreeNode* buildTreeHash1(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0 || preorder.size() != inorder.size()) {
        return nullptr;
    }

    unordered_map<int, int> hashMap;
    for(int i = 0; i < inorder.size(); ++i) {
        auto oPair = hashMap.insert({inorder[i], i});
        if(oPair.second == false) {
            return nullptr;
        }
    }

    return buildTreeUserDict1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, hashMap);
}