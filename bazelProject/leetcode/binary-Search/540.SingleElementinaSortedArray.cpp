#include "540.SingleElementinaSortedArray.h"

int singleNonDuplicate(vector<int>& nums)
{
    if(nums.size() == 1) {
        return nums[0];
    }

    int l = 0, r = nums.size() - 1, mid;
    while(l < r)
    {
        mid = l + ((r - l) >> 1);
        if(nums[mid] == nums[mid + 1]) 
        {
            if(!(mid % 2))  {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }else
        {
            if(mid - 1 >= 0)
            {
                if(nums[mid] == nums[mid - 1])
                {
                    if(!(mid % 2)){
                        r = mid - 1;
                    }else {
                        l = mid + 1;
                    }
                }else {
                    return nums[mid];
                }
            }else {
                return nums[mid];
            }
        }
    }

    return nums[l];
}


int singleNonDuplicate1(vector<int>& nums)
{
    if(nums.size() == 1) {
        return nums[0];
    }

    int l = 0, r = nums.size() - 1, mid;
    while(l + 1 < r)
    {
        mid = l + ((r - l) >> 1);
        if(mid & 0x1)
        {
            if(nums[mid] == nums[mid - 1]) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }else 
        {
            if(nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            }else {
                r = mid;
            }
        }
    }

    return l & 0x1 ? nums[r] : nums[l];
}