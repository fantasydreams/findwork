#include "122.BestTimetoBuyandSellStockII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<int> f = {7,1,5,3,6,4};
    EXPECT_EQ(maxProfit(f), 7);
    EXPECT_EQ(maxProfit1(f), 7);
    EXPECT_EQ(maxProfit2(f), 7);
    EXPECT_EQ(maxProfithungry(f), 7);
    EXPECT_EQ(maxProfitDp(f), 7);
}

TEST(case_2,content)
{
	std::vector<int> f = {1,2,3,4,5};
    EXPECT_EQ(maxProfit(f), 4);
    EXPECT_EQ(maxProfit1(f), 4);
    EXPECT_EQ(maxProfit2(f), 4);
    EXPECT_EQ(maxProfithungry(f), 4);
    EXPECT_EQ(maxProfitDp(f), 4);
}
