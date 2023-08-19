#include "50.Powx.n.h"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>

TEST(case_1, content)
{
    double x = 2.0000;
    int n = 10;
    double ans = 1024.0000;

    EXPECT_EQ(myPow(x, n), ans);
}


TEST(case_2, content)
{
    double x = 2.1000;
    int n = 3;
    double ans = 9.26100;

    EXPECT_EQ(fabs(myPow(x, n) - ans) < 1e10, true);
}


TEST(case_3, content)
{
    double x = 2.00000;
    int n = -2;
    double ans = 0.25000;

    EXPECT_EQ(fabs(myPow(x, n) - ans) < 1e-10, true);
}


TEST(case_4, content)
{
    double x = 2.00000;
    int n = 1;
    double ans = x;

    EXPECT_EQ(myPow(x, n), ans);
}


TEST(case_5, content)
{
    double x = 2.00000;
    int n = 0;
    double ans = 1;

    EXPECT_EQ(myPow(x, n), ans);
}

TEST(case_6, content)
{
    double x = 1.00000;
    int n = INT_MIN;
    double ans = 1;

    EXPECT_EQ(myPow(x, n), ans);
}

TEST(case_7, content)
{
    double x = 1.0000000000001;
    int n = INT_MIN;
    double ans = 0.999785;
    double tmp = myPowx(x, n);

    EXPECT_EQ(fabs(tmp - ans) < 1e-5, true);
    // EXPECT_EQ(tmp, ans);
}

TEST(case_8, content)
{
    double x = 1.0000000000001;
    int n = INT_MIN;
    double ans = 0.999785;
    double tmp = myPow(x, n);

    EXPECT_EQ(fabs(tmp - ans) < 1e-5, true);
    // EXPECT_EQ(tmp, ans);
}