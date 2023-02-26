#include "312.BurstBalloons.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> stocks = {3,1,5,8};
    std::vector<int> stocks1 = {3,1,5,8};
    std::vector<int> stocks2 = {3,1,5,8};
    int ans = 167;
    EXPECT_EQ(maxCoins(stocks), ans);
    EXPECT_EQ(maxCoins1(stocks1), ans);
    EXPECT_EQ(maxCoins2(stocks2), ans);
    
}

TEST(case_2,content)
{
    std::vector<int> stocks = {1,5};
    std::vector<int> stocks1 = {1,5};
    std::vector<int> stocks2 = {1,5};
    int ans = 10;
    EXPECT_EQ(maxCoins(stocks), ans);
    EXPECT_EQ(maxCoins1(stocks1), ans);
    EXPECT_EQ(maxCoins2(stocks2), ans);
}