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