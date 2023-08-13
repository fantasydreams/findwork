#include "41.FirstMissingPositive.h"

int firstMissingPositive(vector<int>& nums) {
    for(int i = 0 ;i < nums.size(); ++i) {
        if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) { // 这里的 nums[num[i] - 1] 特别关键，如果两个相同的数1，1，不加判断的话就会一直死循环
            swap(nums[i], nums[nums[i] - 1]);
            --i;
        }
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != i + 1) {
            return i + 1;
        }
    }

    return nums.size() + 1;
}