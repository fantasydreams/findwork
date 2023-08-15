#include "45.JumpGameII.h"
#include <climits>

int jump(vector<int>& nums) {
    std::vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < nums.size(); ++i) {
        for(int step = 1; step <= nums[i] && i + step < nums.size(); ++step) {
            dp[i + step] = min(dp[i] + 1, dp[i + step]);
        }
    }

    return dp[nums.size() - 1];
}


int jump1(vector<int>& nums) {
    int ans = 0;
    int preMaxPos = 0, curMaxPos = 0, pos = 0;
    while(preMaxPos < nums.size() - 1 && curMaxPos < nums.size() - 1) {
        ++ans;
        preMaxPos = curMaxPos;
        while(pos <= preMaxPos && curMaxPos <= nums.size() - 1) {
            curMaxPos = std::max(curMaxPos, pos + nums[pos]);
            ++pos;
        }
    }

    return ans;
}