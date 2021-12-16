#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>

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
void TraverseTreePreNoRecursion(TreeNode * root);
void TraverseTreePreNoRecursion(TreeNode * root, std::string & res);
void TraverseTreeMid(TreeNode * root);
void TraverseTreeMid(TreeNode * root, std::string & res);
void TraverseTreeMidNoRecursion(TreeNode * root, std::string & res);
void TraverseTreePost(TreeNode * root);
void TraverseTreePost(TreeNode * root, std::string & res);
void TraverseTreePostNoRecursion(TreeNode * root, std::string & res);
void FreeTree(TreeNode * root);
TreeNode * CreateTreePreMid(const std::vector<int> & pre, const std::vector<int> & mid);
TreeNode * CreateTreeMidPost(const std::vector<int> & mid, const std::vector<int> & post);
void TraverseTreeLevelDebug(TreeNode * root);