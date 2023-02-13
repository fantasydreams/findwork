#include "646.MaximumLengthofPairChain.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
   std::vector<std::vector<int>> pair = {{0,1}, {-1,0}, {2, 3}, {-1, 2}};
    int ans = 2;
    EXPECT_EQ(findLongestChain(pair), ans);
}


TEST(case_2,content)
{
   std::vector<std::vector<int>> pair = {{1,2},{2,3},{3,4}};
    int ans = 2;
    EXPECT_EQ(findLongestChain(pair), ans);
}

TEST(case_3,content)
{
   std::vector<std::vector<int>> pair = {{1,2},{7,8},{4,5}};
    int ans = 3;
    EXPECT_EQ(findLongestChain(pair), ans);
}

TEST(case_4,content)
{
   std::vector<std::vector<int>> pair = {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
    int ans = 3;
    EXPECT_EQ(findLongestChain(pair), ans);
}

TEST(case_5,content)
{
   std::vector<std::vector<int>> pair = {{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
    int ans = 4;
    EXPECT_EQ(findLongestChain(pair), ans);
}

