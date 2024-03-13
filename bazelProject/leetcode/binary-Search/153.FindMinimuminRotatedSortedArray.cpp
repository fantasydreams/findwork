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


int findMin1(vector<int>& nums) {
    if(nums.size() == 1 || nums.front() < nums.back()) {
        return nums.front();
    }

    int iBegin = 0, iEnd = nums.size() - 1;
    while(iBegin <= iEnd) {
        if(iBegin == iEnd) {
            return nums[iBegin];
        }

        if(iBegin + 1 == iEnd) {
            return std::min(nums[iBegin], nums[iEnd]);
        }else {
            int iMid = iBegin + ((iEnd - iBegin) >> 1);
            if(nums[iMid] > nums[iBegin] && nums[iMid] > nums[iEnd]) {
                iBegin = iMid + 1;
            }else {
                iEnd = iMid;
            }
        }
    }

    return 0;
}