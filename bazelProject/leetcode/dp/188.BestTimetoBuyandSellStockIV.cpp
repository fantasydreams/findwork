#include "188.BestTimetoBuyandSellStockIV.h"

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