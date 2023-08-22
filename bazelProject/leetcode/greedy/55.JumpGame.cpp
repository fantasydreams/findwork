#include "55.JumpGame.h"

bool canJump(vector<int>& nums) {
    if(nums.empty()) {
        return true;
    }

    int iLastIdx = 0;
    std::vector<bool> vecReach(nums.size(), false);
    vecReach[0] = true;

    for(int i = 0; i < nums.size() && i <= iLastIdx; ++i) {
        if(vecReach[i] && nums[i]) {
            for(int k = 1; k <= nums[i]; ++k) {
                if(k + i >= nums.size() - 1) {
                    return true;
                }
                vecReach[i + k] = true;
                iLastIdx = std::max(iLastIdx, i + k);
            }
        }
    }

    return iLastIdx >= nums.size() - 1;
}


bool canJumpDp(vector<int>& nums) {
    if(nums.empty()) {
        return true;
    }    

    std::vector<bool> dp(nums.size(), false);
    dp[nums.size() - 1] = true;
    int minRightPos = nums.size() - 1;
    for(int pos = minRightPos - 1; pos >= 0; --pos) {
        if(pos + nums[pos] >= minRightPos) {
            dp[pos] = true;
            minRightPos = pos;
        }
    }

    return dp[0];
}