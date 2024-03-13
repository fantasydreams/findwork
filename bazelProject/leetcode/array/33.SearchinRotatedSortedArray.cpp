#include <vector>
#include "33.SearchinRotatedSortedArray.h"
using namespace std;

// all values are unique, 这个同样适用于熟组中存在相等的情况
int search(vector<int>& nums, int target) {
    if(nums.empty()) {
        return -1;
    }

    int low = 0 ,high = nums.size() - 1, mid;
    while(low <= high) {
        mid = low + ((high - low) >> 1);
        if(nums[mid] == target) {
            return mid;
        }else if(nums[mid] > nums[low]) { // 
            if(nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }else if(nums[mid] < nums[high]){
            if(target <= nums[high] && nums[mid] < target) {
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }else {
            if(nums[low] == nums[mid]) {
                ++low;
            }
            if(nums[high] == nums[mid]) {
                --high;
            }
        }
    }

    return -1;
}


int binary_search(vector<int> & nums,int left,int right,int target){
    if(left > right) return -1;
    int mid;
    while(left <= right){
        mid = left + ((right - left) >> 1);
        if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] > target) right = mid - 1;
        else return mid;
    }
    
    return -1;
}
    
int search1(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;
    if(nums.size() == 1) return ((nums[0] == target) ? 0 : -1);
    if(nums[0] < nums[nums.size()-1]) return binary_search(nums,0,nums.size()-1,target);
    size_t left = 0,right = nums.size()-1,mid;
    while(left + 1 < right){
        mid = (left + right) /2;
        if(nums[mid] > nums[left]) left = mid;
        else right = mid;
    }
    
    if(nums[0]<=target && target <= nums[right-1]) 
        return binary_search(nums,0,right-1,target);
    if(nums[right]<=target && target <= nums[nums.size()-1]) 
        return binary_search(nums,right,nums.size()-1,target);
    return -1;
}


int search2(vector<int>& nums, int target) {
    int iBegin = 0, iEnd = nums.size() - 1;
    while(iBegin <= iEnd) {
        int iMid = iBegin + ((iEnd - iBegin) >> 1);
        if(nums[iMid] == target) {
            return iMid;
        }else if(nums[iMid] > nums[iBegin]) {
            if(nums[iBegin] <= target && target < nums[iMid]) {
                iEnd = iMid - 1;
            }else {
                iBegin = iMid + 1;
            }
        }else if(nums[iMid] < nums[iEnd]) {
            if(nums[iMid] < target && target <= nums[iEnd]) {
                iBegin = iMid + 1;
            }else {
                iEnd = iMid - 1;
            }
        }else if(nums[iMid] == nums[iBegin]){
            ++iBegin;
        }else {
            --iEnd;
        }
    }

    return -1;
}