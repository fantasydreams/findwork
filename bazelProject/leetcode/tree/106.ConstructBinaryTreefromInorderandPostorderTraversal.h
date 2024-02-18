#include "treecomm.h"
#include <vector>
using namespace std;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
TreeNode* buildTreeHash(vector<int>& inorder, vector<int>& postorder);
TreeNode* buildTreeHash1(vector<int>& inorder, vector<int>& postorder);