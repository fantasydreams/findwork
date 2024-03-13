#include "172.FactorialTrailingZeroes.h"


// 阶层乘积末尾为0来源于2和5，因为2的数量远大于5，统计5就可以
int trailingZeroes(int n){
    int ans = 0;
    while(n) {
        ans += n / 5;
        n /= 5;
    }

    return ans;
}

// https://blog.csdn.net/fuxuemingzhu/article/details/51347044
int trailingZeroes1(int n){
    int ans = 0;
    while(n) {
        ans += n / 5;
        n /= 5;
    }

    return ans;
}


int trailingZeroes2(int n) {
    int iAns = 0;
    while(n) {
        iAns += n / 5;
        n /= 5;
    }

    return iAns;
}