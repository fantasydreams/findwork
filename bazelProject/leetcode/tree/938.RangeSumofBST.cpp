#include "938.RangeSumofBST.h"


//直接遍历
int rangeSumBST(TreeNode* root, int low, int high) 
{
    if(!root) return 0;
    int leftVal = rangeSumBST(root->left, low, high);
    int rightVal = rangeSumBST(root->right, low, high);
    int sum = leftVal + rightVal + ((root->val >= low && root->val <= high) ? root->val : 0);
    return sum;
}

//利用BST特性，剪枝不必要的遍历

int rangeSumBSTUseBstFeature(TreeNode* root, int low, int high) 
{
    if(!root) return 0;
    if(root->val < low){
        return rangeSumBST(root->right, low, high);
    }else if(root->val >= low && root->val <= high){
        return root->val + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
    }else{
        return rangeSumBST(root->left, low, high);
    }
}