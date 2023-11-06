#include "204.CountPrimes.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    int n = 2, ans = 0;
    EXPECT_EQ(countPrimes(n), ans);
    EXPECT_EQ(countPrimes1(n), ans);
    EXPECT_EQ(countPrimes2(n), ans);
    EXPECT_EQ(countPrimes3(n), ans);
}

TEST(case_2,content)
{   //0 0 1 1 0 1 0 1 0 0 0
    //0 1 2 3 4 5 6 7 8 9 10;
    int n = 10, ans = 4;
    EXPECT_EQ(countPrimes(n), ans);
    EXPECT_EQ(countPrimes1(n), ans);
    EXPECT_EQ(countPrimes2(n), ans);
    EXPECT_EQ(countPrimes3(n), ans);
}

TEST(case_3,content)
{
    int n = 0, ans = 0;
    EXPECT_EQ(countPrimes(n), ans);
    EXPECT_EQ(countPrimes1(n), ans);
    EXPECT_EQ(countPrimes2(n), ans);
    EXPECT_EQ(countPrimes3(n), ans);
}

TEST(case_4,content)
{
    int n = 1, ans = 0;
    EXPECT_EQ(countPrimes(n), ans);
    EXPECT_EQ(countPrimes1(n), ans);
    EXPECT_EQ(countPrimes2(n), ans);
    EXPECT_EQ(countPrimes3(n), ans);
}