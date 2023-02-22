#include "494.TargetSum.h"
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <numeric>


void findTargetSumWays(vector<int>& nums, int pos, int cursum, int target, int & ans)
{
    if(pos >= nums.size())
    {
        if(target == cursum){
            ++ans;
        }
        return;
    }

    findTargetSumWays(nums, pos + 1, cursum + nums[pos], target, ans);
    findTargetSumWays(nums, pos + 1, cursum - nums[pos], target, ans);
} 

int findTargetSumWays(vector<int>& nums, int target)
{
    int ans = 0;
    findTargetSumWays(nums, 0, 0, target, ans);
    return ans;
}


int findTargetSumWays2(vector<int>& nums, int target)
{
    if(nums.size() == 0) {
        return 0;
    }

    std::unordered_map<int, int> map;
    ++map[nums[0]], ++map[-nums[0]];
    for(int i = 1; i < nums.size(); ++i)
    {
        std::unordered_map<int, int> newMap;
        for(const auto & oPair : map) 
        {
            newMap[oPair.first + nums[i]] += oPair.second;
            newMap[oPair.first - nums[i]] += oPair.second;
        }
        swap(newMap, map);
    }
    
    return map[target];
}

void findTargetSumWays1(vector<int>& nums, int pos, int target, int & ans)
{
    if(pos < 0)
    {
        if(target == 0){
            ++ans;
        }
        return;
    }

    findTargetSumWays1(nums, pos - 1, target - nums[pos], ans);
    findTargetSumWays1(nums, pos - 1, target + nums[pos], ans);
} 

int findTargetSumWays1(vector<int>& nums, int target)
{
    int ans = 0;
    findTargetSumWays1(nums, nums.size() - 1, target, ans);
    return ans;
}


//拆成两个集合，一个集合全部做加法A，一个集合全部做减法B，则 A+B=SUM
// A - B = P
//Ａ+ B + A - B = SUM + A - B 即 2A = SUM + P 即 A = （SUM + P）/ 2
//转换成为0 1 背包问题
int findTargetSumWays3(vector<int>& nums, int target)
{
    int sum = std::accumulate(nums.begin(), nums.end(), 0) + target;
    if((sum % 2) & 0x1 || sum < 0) {
        return 0;
    }

    int p = sum >> 1;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
    dp[0][0] = 1; // 没有参数，然后和为0；
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= p; ++j) {
            if(nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]; //可以选的情况下，为选和不选的总数，否则不选
            }else {
                dp[i][j] = dp[i - 1][j]; //不能选的情况下只能用不能选的
            }
        }
    }

    return dp[n][p];
}

//dp将维度
int findTargetSumWays4(vector<int>& nums, int target)
{
    int sum = std::accumulate(nums.begin(), nums.end(), 0) + target;
    if((sum % 2) & 0x1 || sum < 0) {
        return 0;
    }

    int p = sum >> 1;
    int n = nums.size();
    vector<int> dp(p + 1, 0);
    dp[0] = 1; // 没有参数，然后和为0；
    for(int i = 1; i <= n; ++i) {
        for(int j = p; j >= 0; --j) {
            if(nums[i - 1] <= j) {
                dp[j] += dp[j - nums[i - 1]];
            }
        }
    }

    return dp[p];
}