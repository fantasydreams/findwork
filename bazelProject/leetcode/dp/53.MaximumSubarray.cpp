#include "53.MaximumSubarray.h"


int maxSubArray(vector<int>& nums)
{
    if(nums.size() ==  0) {
        return 0;
    }

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int largesum = dp[0];

    for(int i = 1; i < nums.size(); ++i)
    {
        if(dp[i - 1] >= 0) {
            dp[i] = dp[i - 1] + nums[i];
        }else {
            dp[i] = nums[i];
        }

        largesum = std::max(largesum, dp[i]);
    }

    return largesum;
}

int maxSubArray1(vector<int>& nums)
{
    if(nums.size() ==  0) {
        return 0;
    }

    int largesum = nums[0], tmp = nums[0];

    for(int i = 1; i < nums.size(); ++i)
    {
        if(tmp >= 0) {
            tmp += nums[i];
        }else {
            tmp = nums[i];
        }

        largesum = std::max(largesum, tmp);
    }

    return largesum;
}