#include "233.NumberofDigitOne.h"
#include <cstdint>
#include <algorithm>

// https://leetcode.cn/problems/number-of-digit-one/solutions/932573/shu-zi-1-de-ge-shu-by-leetcode-solution-zopq/ 题解
int countDigitOne(int n) {
    int ans = 0;
    long long mulk = 1;
    while(n >= mulk) {
        ans += (n / (mulk * 10)) * mulk + std::min(std::max((n % (mulk * 10)) - mulk + 1, 0LL), mulk);
        mulk *= 10;
    }
    return ans;
}