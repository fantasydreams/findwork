#include "122.BestTimetoBuyandSellStockII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<int> f = {7,1,5,3,6,4};
    EXPECT_EQ(maxProfit(f), 7);
}

TEST(case_2,content)
{
	std::vector<int> f = {1,2,3,4,5};
    EXPECT_EQ(maxProfit(f), 4);
}
