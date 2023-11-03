#include "189.RotateArray.h"
#include <algorithm>

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    if( k == 0) {
        return;
    }

    std::reverse(nums.begin(), nums.begin() + nums.size() - k);
    std::reverse(nums.begin() + nums.size() - k, nums.end()); // [)
    std::reverse(nums.begin(), nums.end());
}
