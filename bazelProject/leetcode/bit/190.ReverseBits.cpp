#include "190.ReverseBits.h"
#include <string>
#include <sstream>

// 右移, 对于有无符号，左移和表现都一样，末尾补零， 对于右移，无符号补零，有符号根据最高位进行复制
uint32_t reverseBits(uint32_t n) {
    uint32_t ans, bit;
    for(int i = 0; i < 32; ++i) {
        bit = n & 0x1;
        n = n >> 1;
        ans = ans << 1;
        ans += bit;
    }

    return ans;
}


uint32_t reverseBits1(uint32_t n) {
    uint32_t ans = 0, bit = 0;
    for(int i = 0;i < 32; ++i) {
        bit = n & 0x1;
        n >>= 1;
        ans <<= 1;
        ans |= bit;
    }

    return ans;
}


uint32_t reverseBits2(uint32_t n) {
    int iAns = 0, iBit = 0;
    for(int i = 0; i < 32; ++i) {
        iBit = n & 0x1;
        n >>= 1;
        iAns = iAns << 1 | iBit;
    }

    return iAns;
}