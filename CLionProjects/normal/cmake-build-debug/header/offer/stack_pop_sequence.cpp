//
// Created by Sharwen on 2020/2/22.
//

#include "../../header/offer/stack_pop_sequence.h"

bool is_stack_pop_sequence(const std::vector<int> & stack_in,const std::vector<int> & stack_out){
    if(stack_in.size() != stack_out.size() || stack_in.size() == 0
        || stack_out.size() == 0){
        return false;
    }

    std::stack<int> s;

    for(size_t out_idx = 0,in_idx = 0;out_idx < stack_out.size();){
        if(s.empty()){
            s.push(stack_in[in_idx++]);
        }else{
            if(s.top() == stack_out[out_idx]){
                s.pop();
                ++out_idx;
            }else{
                s.push(stack_in[in_idx++]);
            }
        }
    }

    return s.empty() ? true : false;
}
