#include "121.BestTimetoBuyandSellStock.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> stocks = {7,1,5,3,6,4};
    int ans = 5;
    EXPECT_EQ(maxProfit(stocks), ans);
    EXPECT_EQ(maxProfit1(stocks), ans);
    EXPECT_EQ(maxProfit2(stocks), ans);
    EXPECT_EQ(maxProfit3(stocks), ans);
    EXPECT_EQ(maxProfit4(stocks), ans);
    EXPECT_EQ(maxProfitMonostoneStack(stocks), ans);
    EXPECT_EQ(maxProfit5(stocks), ans);
    EXPECT_EQ(maxProfitDp(stocks), ans);
    EXPECT_EQ(maxProfitMonostoneStack1(stocks), ans);
}

TEST(case_2,content)
{
    std::vector<int> stocks = {7,6,4,3,1};
    int ans = 0;
    EXPECT_EQ(maxProfit(stocks), ans);
    EXPECT_EQ(maxProfit(stocks), ans);
    EXPECT_EQ(maxProfit2(stocks), ans);
    EXPECT_EQ(maxProfit3(stocks), ans);
    EXPECT_EQ(maxProfit4(stocks), ans);
    EXPECT_EQ(maxProfitMonostoneStack(stocks), ans);
    EXPECT_EQ(maxProfit5(stocks), ans);
    EXPECT_EQ(maxProfitDp(stocks), ans);
    EXPECT_EQ(maxProfitMonostoneStack1(stocks), ans);
}

