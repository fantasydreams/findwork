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