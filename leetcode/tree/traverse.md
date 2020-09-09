# 树的遍历

## 二叉树的遍历
二叉树树的遍历属于树的基本操作，主要分为：

+ 先序遍历
+ 中序遍历
+ 后续遍历
+ 层次遍历
+ 其他

对于树的遍历一般存在两种通用解法，一是递归，二是利用栈来代替递归操作

### 二叉树先序遍历

[144. Binary Tree Preorder Traversal. ](https://leetcode.com/problems/binary-tree-preorder-traversal/)

+ 递归
  + 访问节点内容
  + 递归访问左孩子
  + 递归访问右孩子
  + 递归结束条件：root == nullptr

```C++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre_order(root,res);
        return res;
    }
    
    void pre_order(TreeNode * root,vector<int> &res){
        if(!root) return;
        res.push_back(root->val);
        pre_order(root->left,res);
        pre_order(root->right,res);
    }
};
```

+ 栈
  + 1根结点入栈
  + 2若栈不为空，出栈访问；若栈为空结束      
  + 3若出栈节点右孩子不为空，将右孩子入栈
  + 4若出栈节点左孩子不为空，将左孩子入栈 
  + 5重复步骤2-4  

```C++
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root)return res;
    stack<TreeNode *> st;
    st.push(root);
    while(!st.empty()){
        TreeNode * node = st.top();
        st.pop();
        res.push_back(node->val);
        if(node->right)st.push(node->right);
        if(node->left)st.push(node->left);
    }
    return res;
}
```

### 二叉树中序遍历  
[94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)  
+ 递归
  + 递归访问左孩子
  + 访问节点内容
  + 递归访问右孩子
  + 递归结束条件：root == nullptr

+ 栈
  + 1当前节点若不为空则入栈，否则开始执行3
  + 2若当前节点左孩子不为空，将当前节点左孩子入栈，同时更新左孩子为当前节点，重复2
  + 3若栈不为空，出栈节点，并访问；若栈为空，结束
  + 4将出栈节点的右孩子作为当前节点
  + 5重复1-4

```C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> res;
        push_left_util_null(root,st);
        while(!st.empty()){
            TreeNode * node = st.top();st.pop();
            res.push_back(node->val);
            node = node->right;
            push_left_until_null(node,st);
        }
        return res;
    }
    void push_left_until_null(TreeNode * root,stack<TreeNode *> &st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};
```

### 二叉树后序遍历
[145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)  

+ 递归
  + 递归访问左孩子
  + 递归访问右孩子
  + 访问节点内容
  + 递归结束条件：root == nullptr

+ 栈 + reverse  
对于二叉树的先序遍历非递归代码，是先将根节点的右孩子入栈，然后再左孩子入栈。如果我们将根节点的左孩子先入栈，再入栈后孩子呢会发生什么，细心的同学会发现，交换入栈顺序后，得到的序列恰好是后序遍历的reverse，因此将遍历得到的序列最后进行一次reverse即可得到后序遍历. 
	+ 1根结点入栈
	+ 2若栈不为空，出栈访问；若栈为空,执行6      
	+ 3若出栈节点右孩子不为空，将右孩子入栈
	+ 4若出栈节点左孩子不为空，将左孩子入栈 
	+ 5重复步骤2-4 
	+ 6对得到的序列进行一次reverse操作
```C++
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    stack<TreeNode *> st;st.push(root);
    while(!st.empty()){
        TreeNode * node = st.top();st.pop();
        res.push_back(node->val);
        if(node->left)st.push(node->left);
        if(node->right)st.push(node->right);
    }
    reverse(res.begin(),res.end());
    return res;
}
```

+ 栈 (no reverse)  
与先序遍历和中序遍历不同，这两种栈顶元素直接pop，因此不存在麻烦和困难的点，而后序遍历不同，放在栈顶的一般都是二叉树或者二叉子树的根节点，而根节点在后序遍历中恰恰又是最后访问的，如果根节点的左子树和右子树还未访问，那栈顶是不能出栈的，而若左右子树都已经访问，则可以出栈进行访问。现在的问题就是如何解决让程序知道当前节点的左右子树已经访问过或者没有被访问。最简单的方式是采用一个指针pre，标记上一次访问的节点，如果上一次访问的节点是当前栈顶节点的右孩子，说明当前节点的左右子树都已经被访问，进而出栈访问，同时更新pre. 不难总结得出步骤如下：  
	+ 1若当前节点不为空，入栈.
	+ 2若当前节点左孩子不为空，将当前节点左孩子入栈，同时更新左孩子为当前节点，重复2
	+ 3若栈不为空，得到栈顶节点（注意此时并没有出栈）
	+ 4如果栈顶节点右孩子不为空，判断栈顶节点node右孩子是否为上一次访问的节点(node->right == pre)，如果等于，说明已经访问过了右子树，此时出栈栈顶元素并访问，更新pre为出栈节点；如果不相等，说明右子树未访问，更新当前节点为栈顶右孩子，回到1继续执行。
	+ 5若栈顶右孩子为空，则栈顶元素可直接出栈并访问,更新pre为出栈节点
	+ 6重复3-5

```C++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> st;
        push_left_until_null(root,st);
        TreeNode * pre = nullptr;
        while(!st.empty()){
            TreeNode * node = st.top();
            if(node->right){
                if(node->right == pre){
                    res.push_back(node->val);
                    st.pop();
                    pre = node;
                }else {
                    node = node->right;
                    push_left_until_null(node,st);
                }
            }else {
                res.push_back(node->val);
                st.pop();
                pre = node;
            }
        }
        return res;
    }
    void push_left_until_null(TreeNode * root,stack<TreeNode *> & st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
};
```


### 二叉树的层次遍历

+ 用队列即可实现层次遍历
  + 1若root不为空，入队
  + 2若队列不为空，出队访问
  + 3若出队节点左孩子不为空，入队
  + 4若出队节点右孩子不为空，入队
  + 重复2-4

[102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/).   
[107. Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)  
[637. Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)  
[103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)  


## 树（森林）的遍历
树，与二叉树相比，孩子节点更多，因此只定义三种遍历方式：
+ 先序遍历
+ 后序遍历
+ 层次遍历
因为一个节点的孩子较多，因此对于中序无法定义

### 树的先序遍历
+ 流程与二叉树先序遍历一致，不过由于结果不同，因此有些许差异
	+ 先访问根节点 
	+ 访问根节点的第一个孩子为根节点的子树（仍按照先序的次序）
	+ 访问根节点的第二个孩子为根节点的子树（仍按照先序的次序）
	+ ...
	+ 访问根节点的第最后一个孩子为根节点的子树（仍按照先序的次序）  

### 树的后序遍历
+ 流程与二叉树后序遍历一致，不过由于结果不同，因此有些许差异
	+ 访问根节点的第一个孩子为根节点的子树（仍按照后序的次序）
	+ 访问根节点的第二个孩子为根节点的子树（仍按照后序的次序）
	+ ……
	+ 访问根节点的第最后一个孩子为根节点的子树（仍按照后序的次序） 
	+ 访问根节点

这里重点说一下树的后序遍历的非递归方式
+ 栈+reverse，这里不赘述，和二叉树的栈+reverse基本一致，除了些许差别
	+ 1根结点入栈
	+ 2若栈不为空，出栈访问；若栈为空,执行5      
	+ 3若出栈节点拥有孩子节点，将孩子依次(从左至右 node->children[0] - node->children[node->children.size()-1])入栈
	+ 4重复步骤2-3 
	+ 5对得到的序列进行一次reverse操作

+ 栈(no reverse)  
我们通过二叉树的非递归遍历可知，只要知道当前节点的最后一个孩子已经遍历，则说明此节点所有孩子树已经遍历完成，即可出栈遍历。由于树的孩子节点比较多，我们怎么能知道当前节点是父节点的第几个孩子呢？我们再入栈的时候打包入栈节点的标记，这个标记代表本节点的孩子树已经访问完k(1<=k <=node->children.size())个，若k == node->children.size()出栈访问，否则将node的第k个孩子入栈，同时更新node节点的标记k=k+1;
	+ 1根节点入栈，k = 0
	+ 2若栈不为空，得到栈顶元素（注意此时不是出栈）node和k
	+ 3若k==node->children.size()说明node节点的孩子已经访问玩，出栈访问之，否则压栈node节点的第k+1个孩子以及其对应的标记k = 0
	+ 重复2-3  


```C++
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<pair<Node*,int>> st;
        vector<int> res; 
        if(root==NULL) return res;
        st.push(pair(root,0));
        while(!st.empty()){
            auto &[node,idx] = st.top();
            if(idx == node->children.size()){
                res.push_back(node->val);
                st.pop();
            }else st.push(pair(node->children[idx++],0));
        }
        return res;
    }
};
```
	
[590. N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)  

### 树的层次遍历
+ 与二叉树的层次遍历一样，同样使用队列来完成层次遍历
	+ 1若root不为空，入队
	+ 2若队列不为空，出队访问
	+ 3若出队节点孩子不为空，将所有孩子依次入队
	+ 重复2-4  

[429. N-ary Tree Level Order Traversal](https://leetcode.com/problems/n-ary-tree-level-order-traversal/) 
