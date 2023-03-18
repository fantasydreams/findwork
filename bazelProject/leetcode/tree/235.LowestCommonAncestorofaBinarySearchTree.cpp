#include "235.LowestCommonAncestorofaBinarySearchTree.h"
#include <vector>
using namespace std;

void lowestCommonAncestor(TreeNode* root, TreeNode *p, TreeNode* q, vector<vector<TreeNode*>> &path, bool & find1, bool & find2) {
    if(!root) {
        return;
    }
    
    if(!find1) {
        path[0].push_back(root);
    }
    if(!find2) {
        path[1].push_back(root);
    }

    if(root == p) {
        find1 = true;
    }
    if(root == q) {
        find2 = true;
    }
    
    if(!find1 ||!find2) {
        lowestCommonAncestor(root->left, p, q, path, find1, find2);
    }
    
    if(!find1 || !find2) {
        lowestCommonAncestor(root->right, p, q, path, find1, find2);
    }

    if(!find1) {
        path[0].pop_back();
    }
    if(!find2) {
        path[1].pop_back();
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) {
        return root;
    }

    std::vector<std::vector<TreeNode*>> path(2);
    bool find1 =false, find2 = false;
    lowestCommonAncestor(root, p, q, path, find1, find2);
    TreeNode * ans = nullptr;
    for(int i = 0; i < path[0].size() && i < path[1].size() && (path[0][i] == path[1][i]); ++i) {
        ans = path[0][i];
    }

    return ans;
}

TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val == p->val) return p;
    if(root->val == q->val) return q;
    
    int min = p->val < q->val ? p->val : q->val;
    int max = p->val > q->val ? p->val : q->val;
    if(root->val > min && root->val < max) return root;
    if(root->val > max) return lowestCommonAncestor1(root->left,p,q);
    if(root->val < min) return lowestCommonAncestor1(root->right,p,q);
    return NULL;
}

TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* r=root;
    while(true){
        if(r->val==p->val){return p; break;}
        if(r->val==q->val){return q; break;}
        else if(((r->val)>(p->val) && r->val<q->val) || ((r->val)<(p->val) && (r->val)>(q->val))){return r; break;}
        else if(r->val>p->val && r->val>q->val){
            r=r->left;
        }
        else{
            r=r->right;
        }
    }
}