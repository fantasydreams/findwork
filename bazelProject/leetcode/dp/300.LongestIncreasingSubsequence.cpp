#include "300.LongestIncreasingSubsequence.h"
#include <algorithm>

int lengthOfLIS(vector<int>& nums)
{
    if(nums.size() == 0) {
        return 0;
    }

    int ans = 1;
    std::vector<int> dp(nums.size(), 1);
    for(int i = 1; i < nums.size(); ++i)
    {
        for(int j = i - 1; j >= 0; --j)
        {
            if(nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        ans = std::max(ans, dp[i]);
    }

    return ans;
}

int lengthOfLIS1(vector<int>& nums)
{
    std::vector<int> place;
    for(const auto & num : nums)
    {
        if(place.size() == 0 || place.back() < num) {
            place.push_back(num);
        }else if(place.back() > num) 
        {
            auto pos = lower_bound(place.begin(), place.end(), num) - place.begin();
            place[pos] = num;
        }
    }

    return place.size();
}