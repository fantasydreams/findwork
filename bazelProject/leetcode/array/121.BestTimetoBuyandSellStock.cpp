#include "121.BestTimetoBuyandSellStock.h"
#include <climits>
#include <cmath>

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