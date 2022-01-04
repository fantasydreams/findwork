#include "1009.ComplementofBase10Integer.h"
#include <bitset>
#include <stdio.h>
#include <iostream>
#include <cmath>

int bitwiseComplement(int n)
{
    if(n == 0) return 1;
    std::bitset<32> bit(n);

    int left = 0;
    for(int i=31;i>=0;--i)  //这里的步骤其实也能通过
    {
        if(bit[i] == 1)
        {
            left = i;
            break;
        }
    }

    // std::cout << bit << " " << left << std::endl;
    unsigned int base = 0;
    while(left >= 0)
    {
        base = base + (1 << left);
        // std::cout << base << " " << (1 << left) << std::endl;  //注意，这里 << 的优先级没有 + 高，因此呢如果写作base = base + 1 << left算出来的结果是不对的
        --left;
        
    }
    unsigned int revet = ~n;
    // std::cout << std::bitset<32>(base) << "base" << std::endl
    //           << std::bitset<32>(revet) << std::endl;
    return revet & base;
}


int bitwiseComplementSimple(int n)
{
    int left = (int)log2(std::max(n,1)) + 1;
    unsigned int base = (1 << left) - 1;
    // std::cout << std::bitset<32>(base) << " " << left << std::endl;
    unsigned int revert = ~n;
    return base & revert;
}