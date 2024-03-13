#include "322.CoinChange.h"
#include <climits>

// 完全背包，先遍历空间或者体积 再遍历 空间
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

int coinChange1(vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 2);
    dp[0] = 0;
    for(int i = 1; i <=amount; ++i) {
        for(const auto iCoin : coins) {
            if(i < iCoin) {
                continue;
            }

            dp[i] = std::min(dp[i], dp[i - iCoin] + 1);
        }
    }

    return dp[amount] == amount + 2 ? -1 : dp[amount];
}
