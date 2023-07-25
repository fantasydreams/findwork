#include "27.RemoveElement.h"
int removeElement(std::vector<int>& nums, int val) {
    int istart = 0, iend = 0;
    while(iend < nums.size()) {
        if(nums[iend] != val) {
            nums[istart++] = nums[iend];
        }
        ++iend;
    }

    return istart;
}