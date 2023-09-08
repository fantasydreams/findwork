#include "81.SearchinRotatedSortedArrayII.h"

bool search(vector<int>& nums, int target) {
    if(nums.empty()) {
        return false;
    }

    int left = 0, right = nums.size() - 1, mid;
    while(left <= right) {  
        mid = left + ((right - left) >> 1);
        if(nums[mid] == target) {
            return true;
        }else if(nums[mid] < nums[right]) {
            if(nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }else if(nums[mid] > nums[left]) {
            if(nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }else { //mid 和 left相同的，那么可能增的数据在右侧
            if(nums[left] == nums[mid]) {
                ++left;
            }
            // mid 和right相同， 那么可能mid->right存在增加或者减小的情况
            if(nums[right] == nums[mid]) {
                --right;
            }
        }
    }
    return false;
}