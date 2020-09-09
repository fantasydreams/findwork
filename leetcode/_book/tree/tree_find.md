# 给定一颗树，从树中找到到特定路径或者元素组合
对于本类题目，主要为从树中找到特定元素，或者特定元素组合，或者特定路径  
+ 从树中找到k-sum == target
+ LAC 求公共祖先
+ 找树中的最长路径

## 从树中找到k-sum == target
[653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)  
+ BST后序遍历得到一个非递减数组，然后利用数组的k-sum == target做（详见数组：从数组中寻找寻找特定组合 N-sum）