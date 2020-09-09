//
// Created by Sharwen on 2020/2/22.
//
#include "../../header/offer/has_sub_tree.h"

bool does_subtree(binary_tree_node<int> *p_roo1,binary_tree_node<int> *p_root2);


binary_tree_node<int> * has_subtree(binary_tree_node<int> * p_root1,binary_tree_node<int> *p_root2){
    if(!p_root1 || !p_root2){
        return nullptr;
    }

    binary_tree_node<int> * res =  does_subtree(p_root1, p_root2) ? p_root1 : nullptr;

    if(!res){
        res = has_subtree(p_root1->get_left_child(),p_root2);
    }
    if(!res){
        res = has_subtree(p_root1->get_right_child(),p_root2);
    }

    return res;
}


bool does_subtree(binary_tree_node<int> *p_roo1,binary_tree_node<int> *p_root2){
    if(!p_root2) return true;
    else if(!p_roo1) return false;

//    if(p_roo1->get_value() == p_root2->get_value()){
//        bool left_subtree = does_subtree(p_roo1->get_left_child(),p_root2->get_left_child());
//        bool right_subtree = does_subtree(p_roo1->get_right_child(),p_root2->get_right_child());
//
//        if(left_subtree && right_subtree){
//            return true;
//        }else {
//            return false;
//        }
//    }else{
//        return false;
//    }

    if(p_roo1->get_value() != p_root2->get_value()){
        return false;
    }

    return does_subtree(p_roo1->get_left_child(),p_root2->get_left_child()) && does_subtree(p_roo1->get_right_child(),p_root2->get_right_child());

}