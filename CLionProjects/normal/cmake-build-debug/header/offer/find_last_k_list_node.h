//
// Created by Sharwen on 2020/2/22.
//

#ifndef C___FIND_LAST_K_LIST_NODE_H
#define C___FIND_LAST_K_LIST_NODE_H
#include <iostream>
#include <vector>

struct forward_list_node{
    forward_list_node(int val):_val(val),_next(nullptr){}
    forward_list_node():_val(0),_next(nullptr){}
    int _val;
    forward_list_node * _next;
};

forward_list_node * create_forward_list(const std::vector<int> & data);

forward_list_node * find_last_k_node(forward_list_node * head,size_t k);

forward_list_node * destory_lsit(forward_list_node * head);


#endif //C___FIND_LAST_K_LIST_NODE_H
