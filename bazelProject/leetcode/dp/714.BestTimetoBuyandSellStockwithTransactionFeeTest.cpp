#include "714.BestTimetoBuyandSellStockwithTransactionFee.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<int> prices = {1,3,2,8,4,9};
    int ans = 8, fee = 2;
    EXPECT_EQ(maxProfit(prices, fee), ans);
}
