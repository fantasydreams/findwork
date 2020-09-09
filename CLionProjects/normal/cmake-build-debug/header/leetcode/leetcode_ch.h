//
// Created by sharwen on 2020/3/15.
//

#ifndef C___LEETCODE_CH_H
#define C___LEETCODE_CH_H
#include "../type.h"

class Solution_offer36_a {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node * pre = nullptr;
        convert2list(root,pre);
        while(root->left)root=root->left;
        root->left = pre;
        pre->right = root;
        return root;
    }

    void convert2list(Node *root, Node * &pre){
        stack<Node *> st;
        push_left_util_null(root,st);
        while(!st.empty()){
            Node * node = st.top();st.pop();
            if(pre)pre->right = node;
            node->left = pre;
            pre = node;
            node = node->right;
            push_left_util_null(node,st);
        }
    }

    void push_left_util_null(Node * root,stack<Node *> &st){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};

class Solution_offer36 {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node * pre = nullptr;
        convert2list(root,pre);
        while(root->left)root=root->left;
        root->left = pre;
        pre->right = root;
        return root;
    }

    void convert2list(Node *root, Node * &pre){
        if(!root)return;
        convert2list(root->left,pre);
        if(pre)pre->right = root;
        root->left = pre;
        pre = root;
        convert2list(root->right,pre);
    }
};

class Solution59_2 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        for(int i=0;i<n;++i){
            vector<int> line(n);
            res.push_back(line);
        }

        int _max = n * n,_cur = 1;
        int left = 0,right = n-1,top=0,bottom = n-1;
        while(left <= right && top <= bottom){

            for(int i=left;i<=right && top <= bottom;++i)res[top][i] = _cur++;
            ++top;

            for(int i=top;i<=bottom && left <= right;++i)res[i][right]=_cur++;
            --right;

            for(int i=right;i>=left && top <= bottom;--i) res[bottom][i] = _cur++;
            --bottom;

            for(int i=bottom;i>=top && left <= right;--i) res[i][left] = _cur++;
            ++left;
        }

        return res;
    }
};

#endif //C___LEETCODE_CH_H
