#include "213.HouseRobberII.h"

void dfs(int pos, std::vector<bool> & robed, const std::vector<int> & nums, int & money, int & maxMoney)
{
    if(pos == nums.size())
    {
        if(money > maxMoney) {
            maxMoney = money;
        }
        return;
    }

    
    bool leftRobed = (pos == 0) ? false : robed[pos - 1];
    bool rightRobed = (pos == (nums.size() - 1)) ? robed[0] : false;
    if(!leftRobed && !rightRobed) 
    {
        money += nums[pos];
        robed[pos] = true;
        dfs(pos + 1, robed, nums, money, maxMoney);
        money -= nums[pos];
        robed[pos] = false;
        dfs(pos + 1, robed, nums, money, maxMoney);
    }else {
        dfs(pos + 1, robed, nums, money, maxMoney);
    }
    

    return;
}


int rob(vector<int>& nums)
{
    if(nums.size() <= 0) {
        return 0;
    }

    vector<bool> robed(nums.size(), false);
    int tmp = 0, maxMoney = 0;
    dfs(0, robed, nums, tmp, maxMoney);
    return maxMoney;
}




int rob1(vector<int>& nums)
{
    if(nums.size() <= 3) 
    {
        int _max = 0;
        for(int i = 0; i < nums.size(); ++i) {
            _max = std::max(_max, nums[i]);
        }

        return _max;
    }

    
    std::vector<int> dp(3, 0);
    dp[1] = nums[0];
    for(int i = 1; i < nums.size() - 1; ++i) 
    {
        dp[2] = max(dp[1], dp[0] + nums[i]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    
    std::vector<int> dp1(3, 0);
    dp1[1] = nums[1];
    for(int i = 2; i < nums.size(); ++i) 
    {
        dp1[2] = max(dp1[1], dp1[0] + nums[i]);
        dp1[0] = dp1[1];
        dp1[1] = dp1[2];
    }

    
    return std::max(dp[2], dp1[2]);
}