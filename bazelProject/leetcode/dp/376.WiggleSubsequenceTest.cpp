#include "376.WiggleSubsequence.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1, content)
{
    std::vector<int> coins = {1,7,4,9,2,5};
    int ans = 6;
    EXPECT_EQ(wiggleMaxLength(coins), ans);
    EXPECT_EQ(wiggleMaxLength1(coins), ans);
}


TEST(case_2, content)
{
    std::vector<int> coins = {1,17,5,10,13,15,10,5,16,8};
    int ans = 7;
    EXPECT_EQ(wiggleMaxLength(coins), ans);
    EXPECT_EQ(wiggleMaxLength1(coins), ans);
}

TEST(case_3, content)
{
    std::vector<int> coins = {1,2,3,4,5,6,7,8,9};
    int ans = 2;
    EXPECT_EQ(wiggleMaxLength(coins), ans);
    EXPECT_EQ(wiggleMaxLength1(coins), ans);
}

TEST(case_4, content)
{
    std::vector<int> coins = {0,0};
    int ans = 1;
    EXPECT_EQ(wiggleMaxLength(coins), ans);
    EXPECT_EQ(wiggleMaxLength1(coins), ans);
}

TEST(case_5, content)
{
    std::vector<int> coins = {33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15};
    int ans = 67;
    EXPECT_EQ(wiggleMaxLength(coins), ans);
    EXPECT_EQ(wiggleMaxLength1(coins), ans);
}
