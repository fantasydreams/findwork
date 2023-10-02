// 股票题目模板
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solutions/1/yi-tao-mo-ban-ji-xing-dai-ma-bi-zhao-yan-0ap8/
#include "123.BestTimetoBuyandSellStockIII.h"
#include <climits>
#include <algorithm>
#include <vector>

// 思路一， 取分割点，事件复杂度on2, 容易超时

int maxProfit(vector<int> &prices, int start, int end) {
    int profit = 0;
    int _min = INT_MAX;
    for(int i = start; i <= end; ++i) {
        _min = std::min(prices[i], _min);
        profit = std::max(profit, prices[i] - _min);
    }
    return profit;
}

int maxProfit(vector<int>& prices) {
    std::vector<int> profit(prices.size(), 0);
    for(int i = 0; i < prices.size(); ++i) {
        profit[i] = maxProfit(prices, 0, i) + maxProfit(prices, i + 1, prices.size() - 1);
    }

    return *std::max_element(profit.begin(), profit.end());
}


// 状态转移方程
// https://leetcode.wang/leetcode-123-Best-Time-to-Buy-and-Sell-StockIII.html
int maxProfitDp(vector<int>& prices)  {
    int k  = 2;
    vector<vector<int> >dp(prices.size(), std::vector<int>(k + 1, 0));
    for(int i = 1; i <= k; ++i) {
        int min = prices[0];
        for(int j = 1; j < prices.size(); ++j) {
            min = std::min(prices[j] - dp[j][i - 1], min);
            //min = std::min(prices[j] - dp[j - 1][i - 1], min);
            dp[j][i] = std::max(dp[j - 1][i], prices[j] - min);
        }
    }

    return dp[prices.size() - 1][k];
}