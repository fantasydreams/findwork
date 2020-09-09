//
// Created by Sharwen on 2020/2/22.
//


#include "../../header/offer/mirror_tree.h"

void mirror_tree(binary_tree_node<int> *p_root){
    if(!p_root){
        return;
    }

    binary_tree_node<int> * tmp = p_root->get_left_child();
    p_root->set_left_child(p_root->get_right_child());
    p_root->set_right_child(tmp);

    mirror_tree(p_root->get_left_child());
    mirror_tree(p_root->get_right_child());

}

