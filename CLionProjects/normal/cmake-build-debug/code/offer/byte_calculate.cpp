//
// Created by Sharwen on 2020/2/2.
//

#include "../../header/offer/byte_calculate.h"


int number_of_ones(int num){
    unsigned int byte = 1;
    int count = 0;
    while(byte){
        if(num & byte) ++count;
        byte = byte << 1;
    }

    return count;
}

int number_of_ones_2(int num){
    int count = 0;
    while(num){
        ++count;
        num = num & (num - 1);
    }
    return count;
}
