#include "322.CoinChange.h"

// 求min初始化为最大，求max初始化为最小
int coinChange(vector<int>& coins, int amount)
{
    std::vector<int> dp(amount + 1, amount + 2);
    dp[0] = 0;
    for(int i = 1; i <= amount; ++i)
    {
        for(const auto & coin : coins) 
        {
            if(i >= coin) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == amount + 2 ? -1 : dp[amount];
}