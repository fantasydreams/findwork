#include "162.FindPeakElement.h"
#include <climits>
#include <cstdint>

int findPeakElement(vector<int>& nums) {
    if(nums.size() <= 1) {
        return 0;
    }

    int ans = 0;
    int64_t Pre = INT64_MIN, Post;
    for(int i = 0; i < nums.size(); ++i) {
        Post = (i == nums.size() - 1) ? INT64_MIN : nums[i + 1];
        if(nums[i] > Pre && nums[i] > Post) {
            return i;
        }
        Pre = nums[i];
    }

    return 0;
}