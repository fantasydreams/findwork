//
// Created by Sharwen on 2020/2/4.
//

#include "../../header/offer/1ton.h"
#include <memory>
#include <iostream>

bool increase_one(char * number,int length){
    bool carry = 1;
    int sum = 0;
    for(int i= length-1;i>=0;--i){
        sum = number[i] + carry;
        number[i] = sum % 10;
        carry = sum / 10;

        if(carry ==0 && number[i] < 10){
            break;
        }

        if(carry == 1 && i == 0){
            return true;
        }
    }

    return false;
}

void print(char * number,int length){
    int index = 0;
    while(index < length && number[index] == 0){
        ++index;
    }

    for(;index < length; ++index){
        std::cout << (char)(number[index] + '0');
    }
    std::cout << "\t";
}

void print_one_to_n(int n){
    if(n <= 0) return;

    char * number = new char[n];
    memset_s(number,n,0,n);
    while(!increase_one(number,n)){
        print(number,n);
    }
}

void print_one_to_n_next(char * number,int length,int index){
    if(index == length){
        print(number,length);
        return;
    }
    for(int i=0;i<10;++i){
        number[index] = i;
        print_one_to_n_next(number,length,index + 1);
    }
}




void print_one_to_n_1(int n){
    if(n <= 0) return ;

    char *number = new char[n];
    print_one_to_n_next(number,n,0);

    delete[] number;
}