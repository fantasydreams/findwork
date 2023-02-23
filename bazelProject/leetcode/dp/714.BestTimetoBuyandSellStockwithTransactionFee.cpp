#include <vector>
#include <climits>
#include "714.BestTimetoBuyandSellStockwithTransactionFee.h"


//如果我在今天之后持有股票，那么要么我继续持有我昨天持有的股票，要么我昨天没有持有股票，但今天买入了一股：hold = max(hold, cash - prices[i])
//如果我在今天之后不持有股票，那么要么我昨天没有持有股票，要么我昨天持有股票但我决定今天卖掉它： cash = max(cash, hold + prices[i] - fee ).
//确保费用只发生一次。

int maxProfit(vector<int>& prices, int fee)
{
    int days = prices.size();
    if(days <= 1) {
        return 0;
    }

    int cash = 0, hold = -prices[0];

    for(int i = 1; i < days; ++i) {
        cash = std::max(cash, hold + prices[i] - fee);
        hold = std::max(hold, cash - prices[i]);
    }

    return cash;
}


//有低价就买入，以价格price[i] + fee的价格买入，高于这个价的就卖出，然后后续都按照当前价格进行卖出，如果找到了比这个价格还低的，进行买入，之前的算一次完整的买入卖出
int maxProfit1(vector<int>& prices, int fee)
{
    int buy = INT_MAX, ans = 0;
    for(int i = 0; i < prices.size(); ++i) {
        if(buy > prices[i] + fee) {
            buy = prices[i] + fee;
        }
        if(prices[i] > buy) {
            ans += (prices[i] - buy);
            buy = prices[i];
        }
    }   

    return ans;
}


int maxProfit2(vector<int>& prices, int fee)
{
    int n = prices.size();
    if(n <= 1) {
        return 0;
    }

    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][1] = -prices[0];
    for(int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return dp[n - 1][0];
}


int maxProfit3(vector<int>& prices, int fee)
{
    int n = prices.size();
    if(n <= 1) {
        return 0;
    }

    vector<int> cash(n, 0), hold(n, 0);
    hold[0] = -prices[0];
    for(int i = 1; i < n; ++i) {
        cash[i] = max(cash[i - 1], hold[i - 1] + prices[i] - fee);
        hold[i] = max(hold[i - 1], cash[i - 1] - prices[i]);
    }

    return cash[n - 1];
}


int maxProfit4(vector<int>& prices, int fee)
{
    int n = prices.size();
    if(n <= 1) {
        return 0;
    }

    vector<int> cash(n, 0), hold(n, 0);
    hold[0] = -prices[0];
    for(int i = 1; i < n; ++i) {
        cash[i] = max(cash[i - 1], hold[i - 1] + prices[i] - fee);
        hold[i] = max(hold[i - 1], cash[i - 1] - prices[i]);
    }

    return cash[n - 1];
}

int maxProfit5(vector<int>& prices, int fee)
{
    int n = prices.size();
    if(n <= 1) {
        return 0;
    }

    vector<int> buy(n + 1, INT_MIN / 2), sell(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        buy[i] = max(buy[i - 1], sell[i - 1] - prices[i - 1]);
        sell[i] = max(sell[i - 1], buy[i - 1] + prices[i - 1] - fee);
    }

    return sell[n];
}