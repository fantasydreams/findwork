#include "530.MinimumAbsoluteDifferenceinBST.h"
#include <stack>
#include <climits>
using namespace std;

void PushTaskLeftPathUntilNull(TreeNode * root, std::stack<TreeNode *> & stack);

int getMinimumDifference(TreeNode* root) {
    stack<TreeNode* > st;
    TreeNode * pre = nullptr;
    int ans = INT_MAX;
    PushTaskLeftPathUntilNull(root, st);
    while(!st.empty()) {
        TreeNode * node = st.top();
        st.pop();
        if(pre) {
            ans = std::min(node->val - pre->val, ans);
        }
        pre = node;
        PushTaskLeftPathUntilNull(node->right, st);
    }

    return ans;
}