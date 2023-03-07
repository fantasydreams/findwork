#include "476.NumberComplement.h"

int findComplement(int num) {
    int hOne = 0, tmp = num;
    for(int i = 0; i < 32; ++i) {
        if(tmp & 0x1) {
            hOne = i;
        }
        tmp >>= 1;
    }

    int mask = 1;
    while(hOne) {
        mask = (mask << 1) + 1;
        --hOne;
    }

    return (~num) & mask;
}