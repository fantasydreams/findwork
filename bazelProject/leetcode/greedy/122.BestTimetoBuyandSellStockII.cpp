#include "122.BestTimetoBuyandSellStockII.h"

int maxProfit(std::vector<int>& prices)
{
    int iMax = 0;
    for(int i = 1; i < prices.size(); ++i)
    {
        if(prices[i] > prices[i-1]) {
            iMax += prices[i] - prices[i-1];
        }
    }

    return iMax;
}

int maxProfit1(std::vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < prices.size(); ++i) {
        int diff = prices[i] - prices[i - 1];
        profit += diff > 0 ? diff : 0;
    }

    return profit;
}

// dp[i][0]的意义是第i天买入股票的最大收益，dp[i][1]的意义是第i天卖出股票的最大收益
int maxProfit2(std::vector<int>& prices) {
    std::vector<std::vector<int> > dp(prices.size(), std::vector<int>(2, 0));
    dp[0][0] = -prices[0];
    for(int i = 1; i < prices.size(); ++i) {
        dp[i][0] = std::max(dp[i - 1][0], -prices[i] + dp[i - 1][1]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return dp[prices.size() - 1][1];
}