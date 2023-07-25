#include "26.RemoveDuplicatesfromSortedArray.h"
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    int ans = 0;
    int islow = 0, ifast = 0;
    while(ifast < nums.size()) {
        nums[islow] = nums[ifast++];
        while(ifast < nums.size() && nums[islow] == nums[ifast]) {
            ++ifast;
        }
        ++islow;
    }

    // for(const auto& iNum : nums) {
    //     std::cout << iNum << " ";
    // }
    // std::cout << std::endl;

    return islow;
}

int removeDuplicates1(std::vector<int> &nums) {
    int skipsize = 0;
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i - 1] == nums[i]) {
            ++skipsize;
        }else {
            nums[i - skipsize] = nums[i];
        }
    }

    return nums.size() - skipsize;
}