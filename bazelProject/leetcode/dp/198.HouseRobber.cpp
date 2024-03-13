#include "198.HouseRobber.h"
#include <cmath>

int rob(vector<int>& nums)
{
    if(nums.size() == 1) {
        return nums[0];
    }
    if(nums.size() == 2) {
        return std::max(nums[0], nums[1]);
    }

    std::vector<int> dp(nums.size() + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    dp[2] = nums[1];
    for(int i = 2; i < nums.size(); ++i) {
        dp[i + 1] = max(dp[i - 2] + nums[i], dp[i - 1] + nums[i]);
    }

    return max(dp[nums.size() - 1], dp[nums.size()]);
}

int rob1(vector<int>& nums)
{
    if(nums.size() == 1) {
        return nums[0];
    }

    std::vector<int> dp(nums.size() + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
    }
    return dp[nums.size()];
}

int rob2(vector<int>& nums)
{
    if(nums.size() == 1) {
        return nums[0];
    }

    std::vector<int> dp(3, 0);
    dp[1] = nums[0];
    for(int i = 1; i < nums.size(); ++i) 
    {
        dp[2] = max(dp[1], dp[0] + nums[i]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}

int rob3(vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }

    std::vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        dp[i + 1] = std::max(dp[i], dp[i - 1] + nums[i]);
    }
    return std::max(dp[nums.size()], dp[nums.size() - 1]);
}


int rob4(vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }

    std::vector<int> dp(3, 0);
    dp[1] = nums[0];
    dp[2] = dp[1];

    for(int i = 1; i < nums.size(); ++i) {
        dp[2] = std::max(dp[1], dp[0] + nums[i]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}

int rob5(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }

    std::vector<int> dp(3, 0);
    dp[1] = nums[0];
    dp[2] = dp[1];
    for(int i = 1; i < nums.size(); ++i) {
        dp[2] = std::max(dp[0] + nums[i], dp[1]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    return dp[2];
}