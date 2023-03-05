#include "338.CountingBits.h"

vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        ans[i] = i & 0x1 ? ans[i - 1] + 1 : ans[i >> 1];
    }

    return ans;
}