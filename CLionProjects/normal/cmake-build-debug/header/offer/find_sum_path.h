//
// Created by Sharwen on 2020/2/24.
//

#ifndef C___FIND_SUM_PATH_H
#define C___FIND_SUM_PATH_H
#include "rebuild_binary_tree.h"
#include <vector>

template <class T>
void find_sum_path(binary_tree_node<T> * p_root,int sum,int &cur_sum, std::vector<int> &path){
    if(!p_root){
        return;
    }

    cur_sum += p_root->get_value();
    path.push_back(p_root->get_value());
    bool is_leaf = (p_root->get_left_child() == nullptr) && (p_root->get_right_child() == nullptr);
    if(cur_sum == sum && is_leaf){
        for(auto v : path){
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    find_sum_path(p_root->get_left_child(),sum,cur_sum,path);
    find_sum_path(p_root->get_right_child(),sum,cur_sum,path);

    cur_sum-=p_root->get_value();
    path.pop_back();

}

#endif //C___FIND_SUM_PATH_H
