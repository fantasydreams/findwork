//
// Created by Sharwen on 2020/2/22.
//

#include "../../header/offer/adjustArray.h"

bool isEvent(int val){
    if(val & 0x1){
        return false;
    }
    return true;
}

void ajust_array(int *pData,size_t len, bool (*func)(int val)){
    if(!pData || len <= 0) return;
    size_t left = 0,right = len - 1;

    while(left < right){

        while(left < right && !func(pData[left])){
            ++left;
        }

        while(right > left && func(pData[right])){
            --right;
        }

        if(left < right){
            std::swap(pData[left++],pData[right--]);
        }

    }

}