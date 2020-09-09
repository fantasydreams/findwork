//
// Created by Sharwen on 2020/2/22.
//

#include "../../header/offer/merge_sorted_list.h"

forward_list_node * merge_two_sorted_list(forward_list_node * l1,forward_list_node *l2){
    if(!l1){
        return l2;
    }else if(!l2){
        return l1;
    }
    forward_list_node pre_head = forward_list_node(0),*p1 = l1,*p2 = l2;
    forward_list_node * p = &pre_head;
    while(p1 && p2){
        if(p1->_val < p2->_val){
            p->_next = p1;
            p = p1;
            p1=p1->_next;
        }else{
            p->_next = p2;
            p = p2;
            p2 = p2->_next;
        }
    }

    if(p1){
        p->_next = p1;
    }

    if(p2){
        p->_next = p2;
    }

    return pre_head._next;
}