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