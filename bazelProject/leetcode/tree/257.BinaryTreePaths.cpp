#include "257.BinaryTreePaths.h"


void traceback(TreeNode* node, vector<int> & path, vector<string> & ans)
{
    if(node == nullptr) {
        return;
    }
    path.push_back(node->val);
    if((node->left == nullptr) && (node->right == nullptr))
    {
        std::string str;
        for(int i = 0; i < path.size(); ++i)
        {
            str += std::to_string(path[i]);
            if(i != path.size() - 1) {
                str += "->";
            }
        }
        ans.push_back(move(str));
    }

    traceback(node->left, path, ans);
    traceback(node->right, path, ans);
    path.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root)
{
    std::vector<std::string> ans;
    std::vector<int> path;
    traceback(root, path, ans);
    return ans;
}