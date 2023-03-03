#include "461.HammingDistance.h"
#include <cmath>


//左移
int hammingDistance(int x, int y) {
    int tmp = x ^ y;
    int ans = 0;
    for(int i = 0; i < 32; ++i) {
        uint32_t z = 1 << i;
        z ^ (-z);
        ans += ((tmp & z) > 0 ? 1 : 0);
    }

    return ans;
}

// 获取某一位位1 x ^ (-x) -x = ~x + 1
// 对其内存 (x + bit - 1) & bit ~(x-1)

//右移
int hammingDistance1(int x, int y) {
    int tmp = x ^ y;
    int ans = 0;
    while(tmp) {
        ans += tmp & 0x1;
        tmp = tmp >> 1;
    }

    return ans;
}