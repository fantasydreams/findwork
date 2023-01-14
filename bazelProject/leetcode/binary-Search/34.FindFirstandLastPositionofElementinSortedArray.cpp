#include "34.FindFirstandLastPositionofElementinSortedArray.h"

vector<int> searchRange(vector<int>& nums, int target)
{
    if(nums.size() == 0) {
        return {-1, -1};
    }
    int l = 0, r = nums.size() - 1, mid = 0;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] == target) {
            break;
        }else if(nums[mid] < target){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    if(nums[mid] != target){
        return {-1, -1};
    }

    while(l < nums.size() && nums[l] < target){
        ++l;
    }
    while(r >= 0 && nums[r] > target){
        --r;
    }

    return {l, r};
}


int getLeftIndex(vector<int>& nums, int target, int l, int r)
{
    if(l > r) return -1;
    int mid = 0;
    while(l <= r)
    {
        mid = l + (r -l) / 2;
        if(nums[mid] >= target) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }

    return l;
}

int getrightIndex(vector<int>& nums, int target, int l, int r)
{
    if(l > r) return -1;
    int mid = 0;
    while(l <= r)
    {
        mid = l + (r -l) / 2;
        if(nums[mid] <= target) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    return r;
}

vector<int> searchRange1(vector<int>& nums, int target)
{
    if(nums.size() == 0) {
        return {-1, -1};
    }
    int l = 0, r = nums.size() - 1, mid = 0;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] == target) {
            break;
        }else if(nums[mid] < target){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    if(nums[mid] != target){
        return {-1, -1};
    }

    return {getLeftIndex(nums, target, l, mid), getrightIndex(nums, target, mid ,r)};
}