#include "123.BestTimetoBuyandSellStockIII.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> price = {3,3,5,0,0,3,1,4};
    int profit = 6;
    EXPECT_EQ(maxProfit(price), profit);
    EXPECT_EQ(maxProfitDp(price), profit);
    EXPECT_EQ(maxProfitStat(price), profit);
    EXPECT_EQ(maxProfitDp1(price), profit);
}


TEST(case_2, content) {
    std::vector<int> price = {1,2,3,4,5};
    int profit = 4;
    EXPECT_EQ(maxProfit(price), profit);
    EXPECT_EQ(maxProfitDp(price), profit);
    EXPECT_EQ(maxProfitStat(price), profit);
    EXPECT_EQ(maxProfitDp1(price), profit);
}

TEST(case_3, content) {
    std::vector<int> price = {7,6,4,3,1};
    int profit = 0;
    EXPECT_EQ(maxProfit(price), profit);
    EXPECT_EQ(maxProfitDp(price), profit);
    EXPECT_EQ(maxProfitStat(price), profit);
    EXPECT_EQ(maxProfitDp1(price), profit);
}