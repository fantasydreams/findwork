#include "169.MajorityElement.h"

int majorityElement(vector<int>& nums) {
    int major = nums[0], cnt = 1;
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] == major) {
            ++cnt;
        }else {
            if(cnt) {
                --cnt;
            }else {
                major = nums[i];
                cnt = 1;
            }
        }
    }

    return major;
}


int majorityElement1(vector<int>& nums) {
    int major = nums[0], cnt = 1;
    for(int i = 1; i < nums.size(); ++i) {
        if(major == nums[i]) {
            ++cnt;
        }else {
            if(cnt) {
                --cnt;
            }else {
                major = nums[i];
                cnt = 1;
            }
        }
    }

    return major;
}


int majorityElement2(vector<int>& nums) {
    int iAns = nums[0], iCnt = 1;
    for(int iCursor = 1; iCursor < nums.size(); ++iCursor){
        if(nums[iCursor] == iAns) {
            ++iCnt;
        }else {
            if(iCnt == 0) {
                iAns = nums[iCursor];
                iCnt = 1;
            }else {
                --iCnt;
            }
        }
    }

    return iAns;
}