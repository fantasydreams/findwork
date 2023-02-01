#include "416.PartitionEqualSubsetSum.h"
#include <algorithm>
#include <numeric>

bool canPartition(vector<int>& nums)
{
    if(nums.size() == 0) {
        return true;
    }

    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if(sum & 0x1) {
        return false;
    }

    int half = sum >> 1;
    // 0/1 背包问题，等于从这个多个物品中挑出总价值为half的物品
    std::vector<std::vector<bool>> dp(nums.size() + 1, std::vector<bool>(half + 1, false));
    for(int i = 0; i < nums.size() + 1; ++i) {
        dp[i][0] = true;
    }

    for(int i = 1; i <= nums.size(); ++i) // 这么多个物品，可以看成nums[i]为体积，价值为1
    {
        for(int j = 1; j <= half; ++j) // 这么大的空间
        {
            if(j >= nums[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[nums.size()][half];
}


bool canPartition1(vector<int>& nums) //空间压缩
{
    if(nums.size() == 0) {
        return true;
    }

    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if(sum & 0x1) {
        return false;
    }

    int half = sum >> 1;
    // 0/1 背包问题，等于从这个多个物品中挑出总价值为half的物品
    std::vector<bool> dp(half + 1, false);
    dp[0] = true;
    for(int i = 0; i < nums.size(); ++i) // 这么多个物品，可以看成nums[i]为体积，价值为1
    {
        for(int j = half; j >= nums[i]; --j) { // 这么大的空间 
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    return dp[half];
}