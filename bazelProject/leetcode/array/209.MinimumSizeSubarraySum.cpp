#include "209.MinimumSizeSubarraySum.h"

int minSubArrayLen(int target, vector<int>& nums) {
    int start = 0, end = 0;
    int curSum = 0, minLen = nums.size() + 1;
    while(end <= nums.size()) {
        if(curSum < target) {
            if(end < nums.size()) {
                curSum += nums[end];
            }else {
                break;
            }
            ++end;
        }else {
            minLen = std::min(minLen, end - start);
            curSum -= nums[start];
            ++start;
        }
    }

    return minLen == nums.size() + 1 ? 0 : minLen;
}


int minSubArrayLen2(int target, vector<int>& nums) {
    int iLeft = 0, iRight = 0;
    int iCurmSUm = 0, iAns = nums.size() + 1;
    while(iRight <= nums.size()) {
        if(iCurmSUm < target) {
            if(iRight < nums.size())  {
                iCurmSUm += nums[iRight];
            }
            ++iRight;
        }else {
            iAns = std::min(iAns, iRight - iLeft);
            iCurmSUm -= nums[iLeft++];
        }
    }

    return iAns == nums.size() + 1 ? 0 : iAns;
}