#include "162.FindPeakElement.h"
#include <climits>
#include <cstdint>

int findPeakElement(vector<int>& nums) {
    if(nums.size() <= 1) {
        return 0;
    }

    int ans = 0;
    int64_t Pre = INT64_MIN, Post;
    for(int i = 0; i < nums.size(); ++i) {
        Post = (i == nums.size() - 1) ? INT64_MIN : nums[i + 1];
        if(nums[i] > Pre && nums[i] > Post) {
            return i;
        }
        Pre = nums[i];
    }

    return 0;
}


int findPeakElement1(vector<int>& nums) {
    auto pGet = [&](int iIdx) -> std::pair<int, int> {
        if(iIdx == -1 || iIdx == nums.size()) {
            return {0, INT_MIN};
        }
        return {1, nums[iIdx]};
    };

    int iBegin = 0, iEnd = nums.size() - 1;
    while(iBegin <= iEnd) {
        int iMid = iBegin + ((iEnd - iBegin) >> 1);
        auto iBefore = pGet(iMid - 1);
        auto iMidVal = pGet(iMid);
        auto iAfter = pGet(iMid + 1);
        if( iBefore < iMidVal && iMidVal > iAfter) {
            return iMid;
        }else if(iBefore < iMidVal) {
            iBegin = iMid + 1;
        }else {
            iEnd = iMid - 1;
        }
    }

    return 0;
}