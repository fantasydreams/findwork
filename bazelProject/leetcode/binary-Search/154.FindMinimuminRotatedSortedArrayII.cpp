#include "154.FindMinimuminRotatedSortedArrayII.h"

int findMin(vector<int>& nums)
{
    if(nums.size() == 1) {
        return nums[0];
    }
    int l = 0, r = nums.size() - 1, mid;
    while(r && (nums[r] == nums[0])) {
        --r;
    }

    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] < nums[0]) {
            r = mid - 1;
        }else if(nums[mid] >= nums[0]) 
        {
            if(nums[mid] <= nums[mid] + 1) {
                l = mid + 1;
            }else 
            {
                l = mid;
                break;
            }
        }
    }

    return l >= nums.size() ? nums[0] : nums[l];
}


int findMin1(vector<int>& nums)
{
    if(nums.size() == 1) {
        return nums[0];
    }
    int l = 0, r = nums.size() - 1, mid;

    while(l < r)
    {
        mid = l + ((r - l) >> 1);
        if(nums[mid] > nums[r]) {
            l = mid + 1;
        }else {
            --r;
        }
    }

    return nums[r];
}


int findMin2(vector<int>& nums) {
    if(nums.size() == 1) {
        return nums[0];
    }
    
    int b = 0, e = nums.size() - 1, mid;
    while(b < e) {
        mid = b + ((e - b) >> 1);
        if(nums[mid] > nums[e]) {
            b = mid + 1;
        }else {
            --e;
        }
    }

    return nums[e];
}