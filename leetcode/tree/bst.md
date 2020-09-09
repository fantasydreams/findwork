# 二叉搜索树

二叉搜索树，又名二叉排序树，它或是一颗空树，若非空满足以下条件：  
+ 若左子树不为空，则根节点值大于左子树所有节点的值
+ 若左子树不为空，则根节点值小于右子树所有节点的值
+ 若左右子树不为空，则左右子树也分别为二叉排序树  

不难发现一个二叉搜索树的一个重要性质，中序遍历一颗二叉搜索树得到的是一个递增的数组，除此以外，二叉搜索树的不同遍历组合可以唯一确定一颗二叉树。他们分别是：
+ 先序遍历+中序遍历
+ 后序遍历+中序遍历

对于二叉搜索树出现的题目，主要归纳为
+ BST与双向链表
+ find_kth smallest
+ 给定特定的遍历序列，重建BST/判断是否为BST遍历序列
+ LCA（[LCA跳转](lca.md)）

## BST与双向链表
通过以上分析，BST中序遍历得到一个递增序列。而BST有的节点的指针域是空着的，这些空着的指针域若重新赋值为前驱（left指针域，指向前一个大于本节点值的节点）或者后继（right指针域，指向前一个大于本节点值的节点），即可得到一个双向链表  
[面试题36. 二叉搜索树与双向链表](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)  

+ 定义一个pre节点初始为nullptr，用于记录上一次访问过的节点（当前节点的前驱）
+ 利用递归或者栈的中序遍历 遍历BST，遍历的同时，修改pre和当前节点node的左右孩子域指针
+ pre->right = node;node->left = pre;
+ 更新pre = node  

当遍历完毕后，得到的就是一个完整的双向链表，如果题目要求是一个循环双向链表，则需要通过root的左孩子一直往前遍历(if !root->left then root = root->left)得到root->left == nullptr位置，当前root为链表头节点，再将root和pre(遍历完BST后pre是BST最后的一个节点)链接起来：root->left = pre;pre->right = pre;

[173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)  
+ 转为为list，然后进行next和hasnext操作
	+ 这种思路的时间复杂度集中在BST转换为list的过程中为O(N),空间复杂度为O(h)，h为BST树高
	+ next操作O(1)，hasNext()操作O(1)
+ 转化为list的思路，提前做了转化的工作，然而有的部分转化工作是没必要的（如只有很少的next和hasNext操作），那么可以将转化的过程放到next当中来做  
	+ 时间复杂度next(),最差O(n)，最好O(1)；hasNext() O(1)  

```C++
class BSTIterator {
private:
    stack<TreeNode *>st;
    void push_left_util_null(TreeNode * root,stack<TreeNode *> &st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        push_left_util_null(root,st);
    }
    /** @return the next smallest number */
    int next() {
        TreeNode * node = st.top();st.pop();
        if(node->right)push_left_util_null(node->right,st);
        return node->val;
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};
```

[230. Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)  








