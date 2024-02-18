#include "treecomm.h"
#include <vector>
using namespace std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder);
TreeNode* buildTreeHash(vector<int>& preorder, vector<int>& inorder);
TreeNode* buildTreeHash1(vector<int>& preorder, vector<int>& inorder);