#include "153.FindMinimuminRotatedSortedArray.h"

int findMin(vector<int>& nums) {
    if(nums.size() == 1 || nums[0] < nums.back()) {
        return nums.front();
    }

    int b = 0, e = nums.size() - 1, mid;
    while(b <= e) {
        if(b == e) {
            return nums[b];
        } if(b + 1 == e) {
            return min(nums[b], nums[e]);
        } else {
            mid = b + ((e - b) >> 1);
            if(nums[mid] > nums[b] && nums[b] > nums[e]) {
                b = mid + 1;
            }else {
                e = mid;
            }
        }
    }

    return 0;
}