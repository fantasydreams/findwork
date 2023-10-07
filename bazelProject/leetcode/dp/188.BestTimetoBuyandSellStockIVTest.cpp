#include "188.BestTimetoBuyandSellStockIV.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> stocks = {7,1,5,3,6,4};
    int k = 2, ans = 7;
    EXPECT_EQ(maxProfit(k, stocks), ans);
    EXPECT_EQ(maxProfitDp(k, stocks), ans);
    EXPECT_EQ(maxProfitStat(k, stocks), ans);
}

TEST(case_2,content)
{
    std::vector<int> stocks = {2,4,1};
    int k = 2, ans = 2;
    EXPECT_EQ(maxProfit(k, stocks), ans);
    EXPECT_EQ(maxProfitDp(k, stocks), ans);
    EXPECT_EQ(maxProfitStat(k, stocks), ans);
}

TEST(case_3,content)
{
    std::vector<int> stocks = {3,2,6,5,0,3};
    int k = 2, ans = 7;
    EXPECT_EQ(maxProfit(k, stocks), ans);
    EXPECT_EQ(maxProfitDp(k, stocks), ans);
    EXPECT_EQ(maxProfitStat(k, stocks), ans);
}


TEST(case_4,content)
{
    std::vector<int> stocks = {1,2};
    int k = 1, ans = 1;
    EXPECT_EQ(maxProfit(k, stocks), ans);
    EXPECT_EQ(maxProfitDp(k, stocks), ans);
    
}