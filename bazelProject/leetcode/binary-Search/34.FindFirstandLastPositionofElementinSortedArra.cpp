#include "34.FindFirstandLastPositionofElementinSortedArra.h"
#include <algorithm>
#include <iterator>

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



// lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

// upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

// 在从大到小的排序数组中，重载lower_bound()和upper_bound()

// lower_bound( begin,end,num,greater<type>() ):从数组的begin位置到end-1位置二分查找第一个小于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

// upper_bound( begin,end,num,greater<type>() ):从数组的begin位置到end-1位置二分查找第一个小于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

// auto pIterBegin = std::lower_bound(oDayDataList.item().begin(), oDayDataList.item().end(), oCursorRecord.pass_time(), 
// 												[](const wwopenhwcheckin::AccessData& oData, uint32_t iTime){return oData.pass_time() > iTime;});
// *mid值与value 比较，如果cmp条件成立则frist = mid + 1，掠过前面一半的数据
			
// 	auto pIterEnd = std::upper_bound(pIterBegin, oDayDataList.item().end(), oCursorRecord.pass_time(), 
// 												[](uint32_t iTime, const wwopenhwcheckin::AccessData& oData){return iTime > oData.pass_time();});
//  注意upper_bound是 value 与 *mid进行比较，条件成立则掠过后面一半的数据
vector<int> searchRangeSTL(vector<int>& nums, int target) {
    auto pIter = lower_bound(nums.begin(), nums.end(), target);
    if(pIter == nums.end() || *pIter != target) {
        return {-1, -1};
    }

    auto pIterEnd = upper_bound(pIter, nums.end(), target);
    if(pIterEnd == nums.end()) {
        return {(int)std::distance(nums.begin(), pIter), (int)nums.size()-1};
    }else if(*pIterEnd != target) {
        return {(int)std::distance(nums.begin(), pIter), (int)std::distance(nums.begin(), pIterEnd) - 1};
    }else {
        return {(int)std::distance(nums.begin(), pIter), (int)std::distance(nums.begin(), pIterEnd)};
    }
}


vector<int> searchRangeSTL1(vector<int>& nums, int target) { 
    auto pIterBegin = std::lower_bound(nums.begin(), nums.end(), target);
    if(pIterBegin == nums.end() || *pIterBegin != target) {
        return {-1, -1};
    }
    auto pIterEnd = std::upper_bound(pIterBegin, nums.end(), target);
    if(pIterEnd == nums.end()) {
        return {(int)std::distance(nums.begin(), pIterBegin), int(nums.size() -1)};
    }else if(*pIterEnd != target) {
        return {(int)std::distance(nums.begin(), pIterBegin), int(std::distance(nums.begin(), pIterEnd) -1)};
    }
    return {(int)std::distance(nums.begin(), pIterBegin), (int)std::distance(nums.begin(), pIterEnd)};
}