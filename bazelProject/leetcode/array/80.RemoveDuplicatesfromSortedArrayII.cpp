#include "80.RemoveDuplicatesfromSortedArrayII.h"

int removeDuplicates(vector<int>& nums) {
    int left = 0, cnt = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(left == 0) {
            nums[left++] = nums[i];
            cnt = 1;
        }else {
            if(nums[i] == nums[left - 1]) {
                ++cnt;
                if(cnt < 3) {
                    nums[left++] = nums[i];
                }
            }else {
                nums[left++] = nums[i];
                cnt = 1;
            }
        }
    }

    return left;
}

// 不能保证原地了
int removeDuplicates1(vector<int>& nums) {
    if(nums.size() <= 2) {
        return nums.size();
    }

    std::vector<int> vecOrigin = nums;
    int iElemNum = 2, iCursor = 2;
    while(iCursor < nums.size()) {
        if(vecOrigin[iCursor - 2] != nums[iCursor]) {
            nums[iElemNum++] = nums[iCursor];
        }

        ++iCursor;
    }

    return iElemNum;
}

int removeDuplicates2(vector<int>& nums) {
    if(nums.size() <= 1) {
        return nums.size();
    }

    int iCnt = 1, iElemNum = 1;
    for(int iCursor = 1; iCursor < nums.size(); ++iCursor) {
        if(nums[iCursor] == nums[iCursor - 1]) {
            ++iCnt;
        }else {
            iCnt = 1;
        }

        if(iCnt < 3) {
            nums[iElemNum++] = nums[iCursor];
        }
    }
    return iElemNum;
}