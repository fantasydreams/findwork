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


int removeElement1(std::vector<int>& nums, int val) {
    int iElemNum = 0, iCursor = 0;
    while(iCursor < nums.size()) {
        if(nums[iCursor] != val) {
            nums[iElemNum++] = nums[iCursor];
        }
        ++iCursor;
    }
    return iElemNum;
}