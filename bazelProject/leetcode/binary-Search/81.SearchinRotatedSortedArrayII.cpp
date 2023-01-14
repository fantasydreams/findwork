#include "81.SearchinRotatedSortedArrayII.h"
bool binSearch(const vector<int>& nums, int target, int left, int right)
{
    if(left > right) return false;
    int mid = 0;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            return true;
        }else if(nums[mid] > target){
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }

    return false;
}

bool search(vector<int>& nums, int target)
{
    if(nums.size() == 0) return false;
    if(nums.size() == 1) {
        return nums[0] == target;
    }
    //计算边界
    int l = 0, r = nums.size() - 1, mid = 0;
    while(r && (nums[0] == nums[r])){
        --r;
    }

    if(r == 0){
        return nums[0] == target;
    }
    
    while(l < r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] < nums[0]) {
            r = mid - 1;
        }else if(nums[mid] >= nums[0])
        {
            if(nums[mid] <= nums[mid + 1]){
                l = mid + 1;
            }else 
            {
                l = mid;
                break;
            }
        }
    }

    if(nums[0] <= target && target <= nums[l]) {
        return binSearch(nums, target, 0, l);
    }else {
        return binSearch(nums, target, l + 1, nums.size() - 1);
    }
}

bool search1(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1, mid = 0;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            return true;
        }

        if(nums[left] == nums[mid]) {
            ++left;
        }else if(nums[mid] <= nums[right]) {
            if(nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }else{
            if(nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
    }

    return false;
}