//
// Created by Sharwen on 2020/2/22.
//

#include "../../header/offer/find_last_k_list_node.h"

forward_list_node * create_forward_list(const std::vector<int> & data){
    if(data.size() == 0) return nullptr;

    forward_list_node * head = new forward_list_node(data[0]);
    forward_list_node * p = head;

    for(size_t idx = 1;idx < data.size(); ++idx){
        p->_next = new forward_list_node(data[idx]);
        p=p->_next;
    }

    return head;
}

void destory_list(forward_list_node * head){
    forward_list_node * p;
    while(head){
        p = head;
        head = head->_next;
        delete p;
    }
}


forward_list_node * find_last_k_node(forward_list_node * head, size_t k){
    if(!head || !k) return nullptr;

    forward_list_node * p_node = head, *p_k = head;
    for(size_t i = 1; i < k; ++i){
        p_node = p_node->_next;
        if(!p_node){
            return nullptr;
        }
    }

    while(p_node->_next){
        p_k = p_k->_next;
        p_node = p_node->_next;
    }

    return p_k;
}