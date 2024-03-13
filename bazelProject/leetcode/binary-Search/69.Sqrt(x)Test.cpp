#include "69.Sqrt(x).h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    EXPECT_EQ(mySqrt(1), 1);
    EXPECT_EQ(mySqrt1(1), 1);
    EXPECT_EQ(mySqrt2(1), 1);
    EXPECT_EQ(mySqrt3(1), 1);
    EXPECT_EQ(mySqrt4(1), 1);
}

TEST(case_2,content)
{
    EXPECT_EQ(mySqrt(0), 0);
    EXPECT_EQ(mySqrt1(0), 0);
    EXPECT_EQ(mySqrt2(0), 0);
    EXPECT_EQ(mySqrt3(0), 0);
    EXPECT_EQ(mySqrt4(0), 0);
}

TEST(case_3,content)
{
    EXPECT_EQ(mySqrt(2), 1);
    EXPECT_EQ(mySqrt1(2), 1);
    EXPECT_EQ(mySqrt2(2), 1);
    EXPECT_EQ(mySqrt3(2), 1);
    EXPECT_EQ(mySqrt4(2), 1);
}

TEST(case_4,content)
{
    EXPECT_EQ(mySqrt(3), 1);
    EXPECT_EQ(mySqrt1(3), 1);
    EXPECT_EQ(mySqrt2(3), 1);
    EXPECT_EQ(mySqrt3(3), 1);
    EXPECT_EQ(mySqrt4(3), 1);
}

TEST(case_5,content)
{
    EXPECT_EQ(mySqrt(4), 2);
    EXPECT_EQ(mySqrt1(4), 2);
    EXPECT_EQ(mySqrt2(4), 2);
    EXPECT_EQ(mySqrt3(4), 2);
    EXPECT_EQ(mySqrt4(4), 2);
}

TEST(case_6,content)
{
    EXPECT_EQ(mySqrt(100), 10);
    EXPECT_EQ(mySqrt1(100), 10);
    EXPECT_EQ(mySqrt2(100), 10);
    EXPECT_EQ(mySqrt3(100), 10);
    EXPECT_EQ(mySqrt4(100), 10);
}

TEST(case_7,content)
{
    EXPECT_EQ(mySqrt(65), 8);
    EXPECT_EQ(mySqrt1(65), 8);
    EXPECT_EQ(mySqrt2(65), 8);
    EXPECT_EQ(mySqrt3(65), 8);
    EXPECT_EQ(mySqrt4(65), 8);
}