#include "530.MinimumAbsoluteDifferenceinBST.h"
#include "treecomm.h"
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


int getMinimumDifference1(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int iAns = INT_MAX;
    std::stack<TreeNode*> st;
    PushTaskLeftPathUntilNull(root, st);
    TreeNode* pPre = nullptr;
    while(!st.empty()) {
        TreeNode* pNode = st.top(); st.pop();
        if(pPre) {
            iAns = std::min(pNode->val - pPre->val, iAns);
        }

        pPre = pNode;
        PushTaskLeftPathUntilNull(pNode->right, st);
    }
    return iAns;
}