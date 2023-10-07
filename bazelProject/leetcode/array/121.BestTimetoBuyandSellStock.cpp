#include "121.BestTimetoBuyandSellStock.h"
#include <climits>
#include <cmath>
#include <stack>

int maxProfit(vector<int>& prices)
{
    if(prices.size() == 0 || prices.size() == 1) {
        return 0;
    }

    int _min = prices[0];
    int profit = 0;
    for(int i = 1; i < prices.size(); ++i)
    {
        if(prices[i] - _min > profit) {
            profit = prices[i] - _min;
        }
        if(prices[i] < _min) {
            _min = prices[i];
        }
    }

    return profit;
}

int maxProfit1(vector<int>& prices)
{
    if(prices.size() < 2) {
        return 0;
    }

    int buy = INT_MIN;
    int sell = 0;
    for(int i = 0; i < prices.size(); ++i)
    {
        buy = std::max(buy, -prices[i]);
        sell = std::max(sell, prices[i] + buy);
    }

    return sell;
}


int maxProfit2(vector<int>& prices) {
    int _min = INT_MAX, profit = 0;
    for(const auto & price : prices) {
        _min = std::min(_min, price);
        profit = std::max(profit, price - _min);
    }

    return profit;
}


int maxProfit3(vector<int>& prices) {
    std::vector<std::vector<int> > dp(prices.size(), std::vector<int>(2, 0));
    dp[0][0] = -prices[0], dp[0][1] = 0; // dp[i][0]代表第1天买入股票的最大收益，dp[i][1]代表当天卖出股票的最大收益
    for(int i = 1; i < prices.size(); ++i) {
        dp[i][0] = std::max(dp[i-1][0], -prices[i]);
        dp[i][1] = std::max(dp[i-1][1], prices[i] + dp[i-1][0]);
    }

    return dp[prices.size() - 1][1];
}

// 空间压缩
int maxProfit4(vector<int>& prices) {
    int buyProfit = INT_MIN, sellProfit = 0;
    for(int i = 0; i < prices.size(); ++i) {
        buyProfit = std::max(buyProfit, -prices[i]);
        sellProfit = std::max(sellProfit, buyProfit + prices[i]);
    }

    return sellProfit;
}

int maxProfitMonostoneStack(vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }

    int ans = 0;
    std::stack<int> st; st.push(prices[0]);
    for(int i = 1; i < prices.size(); ++i) {
        while(!st.empty() && st.top() > prices[i]) {
            st.pop();
        }

        if(st.empty()) {
            st.push(prices[i]);
        }else {
            ans = std::max(prices[i] - st.top(), ans);
        }
    }

    return ans;
}