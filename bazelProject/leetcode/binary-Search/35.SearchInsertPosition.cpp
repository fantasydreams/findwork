#include "35.SearchInsertPosition.h"
#include <algorithm>
#include <iterator>

int searchInsert(vector<int>& nums, int target) {
    if(nums.empty()) {
        return 0;
    }

    int low = 0, high = nums.size() - 1, mid;
    while(low <= high) {
        mid = low + ((high-low) >> 1);
        if(nums[mid] == target) {
            return mid;
        }else if(nums[mid] < target) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }

    return low;
}


int searchInsertStl(vector<int>& nums, int target) {
    auto pIter = lower_bound(nums.begin(), nums.end(), target); 
    // if(pIter == nums.end()) {
    //     return nums.size();
    // }

    return std::distance(nums.begin(), pIter);
}