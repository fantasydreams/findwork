#include "164.MaximumGap.h"
#include <sys/resource.h>

int maximumGap(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i = 1; i < nums.size(); ++i) {
        ans = std::max(ans, (nums[i] - nums[i - 1]));
    }

    return ans;
}