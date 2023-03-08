#include "769.MaxChunksToMakeSorted.h"
#include <cmath>

int maxChunksToSorted(vector<int>& arr) {
    int ans = 0, _max = -1;
    for(int i = 0; i < arr.size(); ++i) {
        _max = max(_max, arr[i]);
        if(_max == i) {
            ++ans;
        }
    }

    return ans;
}