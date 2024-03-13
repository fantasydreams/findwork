#include "201.BitwiseANDofNumbersRange.h"
#include <cstdint>

int rangeBitwiseAnd(int left, int right) {
    int ans = left;
    for(int64_t i = (int64_t)left + 1; i <= right && ans; ++i) {
        ans &= i;
    }

    return ans;
}


int rangeBitwiseAndMath(int left, int right) {
    int ans = left;
    while(right > left) {
        ans &= right;
        right = right & (right - 1);
    }
    ans &= left;
    return ans;
}

int rangeBitwiseAnd1(int left, int right) {
    int iAns = left;
    for(int64_t i = left + 1; iAns && i <= right; ++i) {
        iAns &= i;
    }

    return iAns;
}


// https://blog.csdn.net/qq_42956653/article/details/121863260

int rangeBitwiseAnd2(int left, int right) { 
    int iShift = 0;
    while(left != right) {
        left >>= 1;
        right >>= 1;
        ++iShift;
    }

    return left << iShift;
}