#include "29.DivideTwoIntegers.h"
#include <climits>
#include <cstdlib>

int divide(int dividend, int divisor) {
    if(divisor == 0) {
        return 0;
    }
    if(dividend == divisor) {
        return 1;
    }

    if(dividend == INT_MIN && divisor == -1) { // 理论上只有这种情况
        return INT_MAX;
    }

    bool positive = dividend < 0 == divisor < 0;
    uint32_t a = abs(dividend), b = abs(divisor); // 这里要注意溢出

    if(b == 1) {
        return positive ? a : -a;
    }

    int ans = 0;
    while(a >= b) {
        int partQueto = 0, i = 0;
        while((uint64_t)b * (1 << i) <= a) { // 这里也要注意溢出
            partQueto = (1 << i);
            ++i;
        }

        ans += partQueto;
        a -= partQueto * b;
    }

    return positive ? ans : -ans;
}