#include "188.BestTimetoBuyandSellStockIV.h"
#include <climits>
#include <vector>

int maxprofit_(const vector<int> & prices)
{
    int _max = 0;
    for(int i = 1; i < prices.size(); ++i)
    {
        if(prices[i] > prices[i - 1]) {
            _max += (prices[i] - prices[i - 1]);
        }
    }
    return _max;
}

int maxProfit(int k, vector<int>& prices)
{
    int days = prices.size();
    if(days < 2) {
        return 0;
    }else if(k >= days) {
        return maxprofit_(prices);
    }else 
    {
        std::vector<int> buy(k + 1, INT_MIN);
        std::vector<int> sell(k + 1, 0);
        for(int i = 0; i < prices.size(); ++i)
        {
            for(int j = 1; j <= k; ++j)
            {
                buy[j] = std::max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = std::max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }

    return 0;
}


int maxProfitDp(int k, vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }else if(k >= prices.size()) {
        return maxprofit_(prices);
    }else {
        std::vector<std::vector<int> > dp(prices.size(), std::vector<int>(k + 1, 0));
        for(int t = 1; t <= k; ++t) {
            int _min = prices[0];
            for(int i = 1; i < prices.size(); ++i) {
                _min = std::min(_min, prices[i] - dp[i][t - 1]);
                dp[i][t] = std::max(dp[i - 1][t], prices[i] -_min); // 进行了t次交易，要么是昨天已经进行了t次，要么就是昨天进行了t-1今日卖出t次
            }
        }

        return dp[prices.size() - 1][k];
    }
    
    return 0;
}

int maxProfitStat(int k, vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }else if(k >= prices.size()) {
        return maxprofit_(prices);
    }else {
        std::vector<int> buy(k + 1, INT_MIN);
        std::vector<int> sell(k + 1, 0);

        for(int i = 0; i < prices.size(); ++i) {
            for(int t = 1; t <= k; ++t) {
                buy[t] = std::max(sell[t - 1] - prices[i], buy[t]); // 要么买入，要么不买，不买就是buy[t]
                sell[t] = std::max(prices[i] + buy[t], sell[t]); // 要么卖出，要么布卖，不买就是sell[t]
            }
        }
        return sell[k];
    }
    
    return 0;
}


int maxProfitDp1(int k, vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }else if(k >= prices.size()) {
        return maxprofit_(prices);
    }else {
        std::vector<std::vector<int> >dp(prices.size(), std::vector<int>(k + 1, 0));
        for(int i = 1; i <= k; ++i) {
            int _min = prices[0];
            for(int j = 1; j < prices.size(); ++j) {
                _min = std::min(_min, prices[j] - dp[j][i - 1]);  // price[i] - price[j] + dp[j - 1][k-1] = price[i] - price[j] + dp[j][i - 1];
                dp[j][i] = std::max(dp[j - 1][i], prices[j] - _min);
            }
        }

        return dp[prices.size() - 1][k];
    }
}


int maxProfitStat1(int k, vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }else if(k >= prices.size()) {
        return maxprofit_(prices);
    }else {
        std::vector<int> buy(k + 1, INT_MIN);
        std::vector<int> sell(k + 1, 0);

        for(int i = 0; i < prices.size(); ++i) {
            for(int j = 1; j <= k; ++j) {
                buy[j] = std::max(sell[j - 1] - prices[i], buy[j]);
                sell[j] = std::max(sell[j], prices[i] + buy[j]);
            }
        }
        return sell[k];
    }
    
    return 0;
}