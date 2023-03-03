#include "342.PowerofFour.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    int x = 0;
    bool ans =false;
    EXPECT_EQ(isPowerOfFour(x), ans);
}


TEST(case_2,content)
{
    int x = 1;
    bool ans = true;
    EXPECT_EQ(isPowerOfFour(x), ans);
}


TEST(case_3,content)
{
    int x = 2;
    bool ans = false;
    EXPECT_EQ(isPowerOfFour(x), ans);
}

TEST(case_4,content)
{
    int x = 4;
    bool ans = true;
    EXPECT_EQ(isPowerOfFour(x), ans);
}

TEST(case_5,content)
{
    int x = 32;
    bool ans = false;
    EXPECT_EQ(isPowerOfFour(x), ans);
}

TEST(case_6,content)
{
    int x = 64;
    bool ans = true;
    EXPECT_EQ(isPowerOfFour(x), ans);
}

TEST(case_7,content)
{
    int x = 5;
    bool ans = false;
    EXPECT_EQ(isPowerOfFour(x), ans);
}