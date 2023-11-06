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