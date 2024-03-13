#include "918.MaximumSumCircularSubarray.h"
#include <algorithm>

// nb的思路
// https://leetcode.jp/leetcode-918-maximum-sum-circular-subarray-%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF%E5%88%86%E6%9E%90/

int maxSubarraySumCircular(vector<int>& nums) {
    int iAns = nums[0];
    int iTmp = 0;
    for(const auto & iNum : nums) {
        if(iTmp > 0) {
            iTmp += iNum;
        }else {
            iTmp = iNum;
        }

        iAns = std::max(iTmp, iAns);
    }

    int iMin = nums[0];
    iTmp = 0;
    int iTotalNum = 0;
    for(int i = 0; i < nums.size(); ++i) {
        iTotalNum += nums[i];
        if(iTmp < 0) {
            iTmp += nums[i];
        }else {
            iTmp = nums[i];
        }
        iMin = std::min(iMin, iTmp);
    }

    iAns = iTotalNum == iMin ? iAns : std::max(iAns, iTotalNum - iMin);
    return iAns;
}