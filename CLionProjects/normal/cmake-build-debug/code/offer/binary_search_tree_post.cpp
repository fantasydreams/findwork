//
// Created by Sharwen on 2020/2/22.
//

#include "../../header/offer/binary_search_tree_post.h"


bool binary_search_tree_post(const std::vector<int> &sequence, size_t start ,size_t end){
    if(start >= end){
        return true;
    }

    size_t l_idx = start;
    while(l_idx < end && sequence[l_idx++] < sequence[end]);

    size_t r_idx = l_idx;
    while(r_idx < end && sequence[r_idx++] > sequence[end]);

    if(r_idx != end){
        return false;
    }else{
        return binary_search_tree_post(sequence,start,l_idx-1) && binary_search_tree_post(sequence,l_idx,end-1);
    }
}

bool is_binary_search_tree_post(const std::vector<int> &sequence){
    if(sequence.size() == 0) return false;
    return binary_search_tree_post(sequence,0,sequence.size()-1);
}


