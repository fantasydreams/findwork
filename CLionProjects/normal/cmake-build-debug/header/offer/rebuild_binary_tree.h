//
// Created by Sharwen on 2020/1/29.
//

#ifndef C___REBUILD_BINARY_TREE_H
#define C___REBUILD_BINARY_TREE_H
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
template<class T>
class binary_tree_node{
public:
    binary_tree_node(){left_child=NULL;right_child = NULL;};
    binary_tree_node(T v){left_child=NULL;right_child = NULL; value = v;};
    T get_value(){ return value;};
    binary_tree_node & operator = (const binary_tree_node & v){
        this->value = v.get_value();
    }
    void set_value(T value){
        this->value = value;
    }

    void set_left_child(binary_tree_node<T> * const child){
        left_child = child;
    }

    binary_tree_node<T> * get_left_child(){
        return left_child;
    }

    void set_right_child(binary_tree_node<T> * const child){
        right_child = child;
    }

    binary_tree_node<T> * get_right_child(){
        return right_child;
    }
private:
    binary_tree_node * left_child;
    binary_tree_node * right_child;
    T value;
};

template<class T>
class rebuild_binary_tree{
public:
    binary_tree_node<T> * RBT(const vector<T> & pre_order, const vector<T> &in_order, int pre_left,int pre_right,int in_left,int in_right){
        if(pre_left > pre_right) return NULL;

        int in_first_of_ore;
        for(int i=in_left;i<=in_right;++i){
            if(pre_order[pre_left] == in_order[i]){
             in_first_of_ore = i;
            }
        }
        binary_tree_node<T> * root = new binary_tree_node<T>(pre_order[pre_left]);
        root->set_left_child(RBT(pre_order,in_order,pre_left + 1,pre_left + in_first_of_ore -in_left ,in_left,in_first_of_ore - 1));
        root->set_right_child(RBT(pre_order,in_order,pre_left + in_first_of_ore - in_left + 1,pre_right,in_first_of_ore + 1,pre_right));
        return root;
    }

    void pre_traverse(binary_tree_node<T> * const root)const{
        if(!root) return;
        cout << root->get_value() << " ";
        pre_traverse(root->get_left_child());
        pre_traverse(root->get_right_child());
    }

    void in_traverse(binary_tree_node<T> * const root)const{
        if(!root) return;
        in_traverse(root->get_left_child());

        cout << root->get_value() << " ";

        in_traverse(root->get_right_child());
    }

    void post_traverse(binary_tree_node<T> *const root)const{
        if(!root) return;
        post_traverse(root->get_left_child());
        post_traverse(root->get_right_child());

        cout << root->get_value() << " ";

    }


    void level_traverse(binary_tree_node<T> * const root)const{
        if(!root) return;
        queue<binary_tree_node<T> *> Q;
        Q.push(root);

        while(!Q.empty()){
            binary_tree_node<T> * node = Q.front(); Q.pop();

            cout << node->get_value() << " ";

            if(node->get_left_child() != NULL){
                Q.push(node->get_left_child());
            }
            if(node->get_right_child() != NULL){
                Q.push(node->get_right_child());
            }
        }

    }

    void destory_binary_tree(binary_tree_node<T> * const root){
        if(!root) return;
        destory_binary_tree(root->get_left_child());
        destory_binary_tree(root->get_right_child());
        delete root;
    }
};
#endif //C___REBUILD_BINARY_TREE_H
