#include "152.MaximumProductSubarray.h"
#include <algorithm>
#include <climits>

int maxProduct(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }

    std::vector<int> Max(nums.size(), INT_MIN), Min(nums.size(), INT_MAX);
    Max[0] = nums[0], Min[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        Max[i] = std::max(std::max(Max[i - 1] * nums[i], Min[i - 1] * nums[i]), nums[i]);
        Min[i] = std::min(std::min(Max[i - 1] * nums[i], Min[i - 1] * nums[i]), nums[i]);
    }
    
    return *max_element(Max.begin(), Max.end());
}