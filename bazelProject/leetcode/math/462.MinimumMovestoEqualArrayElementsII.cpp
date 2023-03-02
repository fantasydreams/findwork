#include "462.MinimumMovestoEqualArrayElementsII.h"
#include <algorithm>

int minMoves2(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }

    std::sort(nums.begin(), nums.end());
    std::vector<int64_t> left;
    left.push_back(0);

    for(int i = 1; i < nums.size(); ++i) {
        left.push_back(left.back() + i * (nums[i] - nums[i - 1]));
    }

    int64_t ans = left.back(), right = 0;
    for(int i = nums.size() - 2; i >= 0; --i) {
        right += (nums.size() - 1 - i) * (nums[i + 1] - nums[i]);
        int64_t tmp = left[i] + right;
        if(tmp < ans) {
            ans = tmp;
        }else if(tmp > ans) {
            break;
        }
    }

    return ans;
}