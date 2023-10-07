#include "714.BestTimetoBuyandSellStockwithTransactionFee.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<int> prices = {1,3,2,8,4,9};
    int ans = 8, fee = 2;
    EXPECT_EQ(maxProfit(prices, fee), ans);
    EXPECT_EQ(maxProfit1(prices, fee), ans);
    EXPECT_EQ(maxProfit2(prices, fee), ans);
    EXPECT_EQ(maxProfit3(prices, fee), ans);
    EXPECT_EQ(maxProfit4(prices, fee), ans);
    EXPECT_EQ(maxProfit5(prices, fee), ans);
    EXPECT_EQ(maxProfit6(prices, fee), ans);
    EXPECT_EQ(maxProfit7(prices, fee), ans);
}
