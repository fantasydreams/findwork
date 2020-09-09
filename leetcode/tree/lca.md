# 最近公共祖先LCA(Lowest Common Ancestor)

## 定义  
最近公共祖先简称 LCA（Lowest Common Ancestor）。两个节点的最近公共祖先，就是这两个点的公共祖先里面，离根最远的那个。 为了方便，我们记某点集S = {v1,v2,......,vn}的最小公共祖先为LCA(v1,v2,...,vn)或者LCA(S)  
+ 性质
	+ LCA(v) = v
	+ u是v的祖先，则LCA(u,v) = u
	+ 若u，v均不是对方的祖先，则u和v在LCA(u,v)的不同子树中  


## 朴素
### BST LCA  
+ BST的最近公共祖先是LCA比较特殊的一种情况，几种判定结果为：
	+ 若node节点的值均大于p,q节点的值，则LCA(p,q)在node的左子树
	+ 若node节点的值均小于p,q节点的值，则LCA(p,q)在node的右子树
	+ 若node节点的值大于等于其中一个节点的值，且小于等于另一个值，则LCA(p,q) == node. 
	+ 时间复杂度O(h)，h为树高，时间复杂度O(1)

```C++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root || !p || !q) return nullptr;
    if(p->val > q->val)swap(p,q);

    while(root){
        if(root->val < p->val) root = root->right;
        else if(root->val > q->val)root = root->left;
        else return root;
    }
    return nullptr;
}
```

### 普通二叉树
普通二叉树由于不具备BST的性质，那么最直接的方式是通过计算每个节点的祖先路径，然后对比两个路径得到最近公共祖先  
+ 时间复杂度，依次查询O(N)，N为树的节点数量

```C++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *>p_ans,q_ans;
        get_ancestor_path(root,p_ans,p);
        get_ancestor_path(root,q_ans,q);
        int len = min(p_ans.size(),q_ans.size());
        TreeNode * res = nullptr;
        for(int i =0;i < len && p_ans[i] == q_ans[i];++i)res = p_ans[i];
        return res;
    }
    bool get_ancestor_path(TreeNode * root,vector<TreeNode *> &path,  TreeNode * p){
        if(!root) return false;
        path.push_back(root);
        if(root == p) return true;
        bool res = get_ancestor_path(root->left,path,p);
        if(!res) res = get_ancestor_path(root->right,path,p);
        if(!res) path.pop_back();
        return res;
    }
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return nullptr;
        if(root == p || root == q) return root;
        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode * right = lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        else return nullptr;
    }
};
```

然而以上的算法对于少量的查询性能还能接受，如果进行批量查询，则将难以忍受龟速效率  
## Tarjan算法（DFS+并查集）  

