#include "31.NextPermutation.h"
#include <algorithm>

// https://blog.csdn.net/fuxuemingzhu/article/details/82113409
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while(i >= 0 && nums[i] >= nums[i + 1]) { // 注意这里的 num[i] >= num[i + 1]找第一个降序的
        --i;
    }

    if(i >= 0) {
        int j = nums.size() - 1;
        while(j > i && nums[j] <= nums[i]) { // 注意这里的num[j] <= nums[i] 找第一个与当前元素升序的
            --j;
        }
        swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}

void nextPermutationStl(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}


// 1 2 3 4
// 1 2 4 3
// 1 3 2 4
// 1 3 4 2