#include "bytedance.balljump.h"

double nJumpLen(int height, int n)
{
    if ( n == 1) {
        return height;
    }

    double back = height;
    double ans = back;
    for(int i = 1; i < n; ++i) {
        ans += back;
        back /= 2;
    }

    return ans;
}
