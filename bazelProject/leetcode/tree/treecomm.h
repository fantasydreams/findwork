#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

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
void TraverseTreePre(TreeNode * root, std::string & res);
void TraverseTreeMid(TreeNode * root);
void TraverseTreeMid(TreeNode * root, std::string & res);
void TraverseTreePost(TreeNode * root);
void TraverseTreePreNoRecursion(TreeNode * root);
void FreeTree(TreeNode * root);
void TraverseTreePost(TreeNode * root, std::string & res);
TreeNode * CreateTree(const std::vector<int> pre, const std::vector<int> mid);
void TraverseTreeLevelDebug(TreeNode * root);