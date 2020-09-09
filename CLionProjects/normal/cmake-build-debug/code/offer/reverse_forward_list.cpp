//
// Created by Sharwen on 2020/2/22.
//

#include "../../header/offer/reverse_forward_list.h"

forward_list_node * reverse_forward_list(forward_list_node * head){
    if(!head){
        return nullptr;
    }

    forward_list_node * reverse_head = nullptr;
    forward_list_node * old_list = head;
    forward_list_node * node = nullptr;
    while(old_list){
        node = old_list;
        old_list= old_list->_next;
        node->_next = reverse_head;
        reverse_head = node;
    }

    return reverse_head;
}
