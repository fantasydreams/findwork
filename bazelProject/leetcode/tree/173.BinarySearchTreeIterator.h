#include "treecomm.h"
#include <stack>


class BSTIterator {
public:
    BSTIterator(TreeNode* root) {        
        pushStackUtilLeftNull(root);
    }
    
    int next() {
        TreeNode* pNode = st.top();
        st.pop();
        pushStackUtilLeftNull(pNode->right);

        return pNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:

    void pushStackUtilLeftNull(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
    std::stack<TreeNode*> st;
};