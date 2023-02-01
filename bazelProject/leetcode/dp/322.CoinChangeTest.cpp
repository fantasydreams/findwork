#include "322.CoinChange.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1, content)
{
    std::vector<int> coins = {1, 2, 5};
    int amount = 11, ans = 3;
    EXPECT_EQ(coinChange(coins, amount), ans);
}

TEST(case_2, content)
{
    std::vector<int> coins = {2};
    int amount = 3, ans = -1;
    EXPECT_EQ(coinChange(coins, amount), ans);
}

TEST(case_3, content)
{
    std::vector<int> coins = {1};
    int amount = 0, ans = 0;
    EXPECT_EQ(coinChange(coins, amount), ans);
}