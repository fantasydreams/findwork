#include "309.BestTimetoBuyandSellStockwithCooldown.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> stocks = {1,2,3,0,2};
    int ans = 3;
    EXPECT_EQ(maxProfit1(stocks), ans);
    EXPECT_EQ(maxProfit(stocks), ans);
    EXPECT_EQ(maxProfitStat(stocks), ans);
    EXPECT_EQ(maxProfitStat1(stocks), ans);
}

TEST(case_2,content)
{
    std::vector<int> stocks = {1};
    int ans = 0;
    EXPECT_EQ(maxProfit1(stocks), ans);
    EXPECT_EQ(maxProfit(stocks), ans);
    EXPECT_EQ(maxProfitStat(stocks), ans);
    EXPECT_EQ(maxProfitStat1(stocks), ans);
}