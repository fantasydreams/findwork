#include "34.FindFirstandLastPositionofElementinSortedArra.h"

vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, mid;
    while(low <= high) {
        mid = low + ((high - low) >> 1);
        if(nums[mid] == target) {
            break;
        } else if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if(mid < 0 || mid >= nums.size() || nums[mid] != target) {
        return {-1, -1};
    }

    // 这下面还可以进一步用二分进行优化
    int left = mid, right = mid;
    while(left > 0 && nums[left - 1] == target) {
        --left;
    }
    while(right < nums.size() - 1 && nums[right + 1] == target) {
        ++right;
    }

    return {left, right};
}