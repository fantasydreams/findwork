#include <map>
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



void TraverseTreePre(TreeNode * root);
void TraverseTreeMid(TreeNode * root);
void TraverseTreePost(TreeNode * root);
void TraverseTreePreNoRecursion(TreeNode * root);