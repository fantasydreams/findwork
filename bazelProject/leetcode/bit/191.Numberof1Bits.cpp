#include "191.Numberof1Bits.h"
int hammingWeight(uint32_t n) {
    int ans = 0;
    while(n) {
        if(n & 0x1) {
            ++ans;
        }
        n >>= 1;
    }

    return ans;
}

int hammingWeight1(uint32_t n) {
    int iAns = 0;
    while(n) {
        iAns += n & 0x1;
        n >>= 1;
    }

    return iAns;
}