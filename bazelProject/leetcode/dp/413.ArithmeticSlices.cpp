#include "413.ArithmeticSlices.h"
#include <algorithm>
#include <functional>
#include <numeric>

int numberOfArithmeticSlices(vector<int>& nums)
{
    if(nums.size() < 3) {
        return 0;
    }

    std::vector<int> diff(nums.size(), 0);
    std::vector<int> dp(nums.size(), 0);
    diff[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        diff[i] = nums[i] - nums[i - 1];
    }

    dp[1] = 0;
    for(int i = 2; i < nums.size(); ++i) {
        dp[i] = (diff[i] == diff[i - 1]) ? dp[i - 1] + 1 : dp[i];
    }

    int sum = 0;
    for(int i = 0; i < dp.size(); ++i) {
        sum += dp[i] > 0 ? dp[i] : 0;
    }
    return sum;
}


int numberOfArithmeticSlices1(vector<int>& nums)
{
    if(nums.size() < 3) {
        return 0;
    }

    std::vector<int> dp(nums.size(), 0);
    for(int i = 2; i < nums.size(); ++i) 
    {
        if((nums[i] - nums[i - 1]) == nums[i - 1] - nums[i - 2]) {
            dp[i] = dp[i - 1] + 1;
        }
    }

    return std::accumulate(dp.begin(), dp.end(), 0);
}