#include "313.SuperUglyNumber.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    int n = 12, ans = 32;
    vector<int> primes = {2,7,13,19};
    EXPECT_EQ(nthSuperUglyNumber(n, primes), ans);
}

TEST(case_2,content)
{
    int n = 1, ans = 1;
    vector<int> primes = {2,3,5};
    EXPECT_EQ(nthSuperUglyNumber(n, primes), ans);
}