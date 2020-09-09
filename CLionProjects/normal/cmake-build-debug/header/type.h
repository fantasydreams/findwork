//
// Created by sharwen on 2020/3/29.
//

#ifndef C___TYPE_H
#define C___TYPE_H
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <set>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class f_Node {
public:
    int val;
    vector<f_Node*> children;

    f_Node() {}

    f_Node(int _val) {
        val = _val;
    }

    f_Node(int _val, vector<f_Node*> _children) {
        val = _val;
        children = _children;
    }
};

#endif //C___TYPE_H
