#include "326.PowerofThree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    int x = 1;
    bool ans = true;
    EXPECT_EQ(isPowerOfThree(x), ans);
    EXPECT_EQ(isPowerOfThree1(x), ans);
}

TEST(case_2, content)
{
    int x = -1;
    bool ans = false;
    EXPECT_EQ(isPowerOfThree(x), ans);
    EXPECT_EQ(isPowerOfThree1(x), ans);
}

TEST(case_3, content)
{
    int x = 0;
    bool ans = false;
    EXPECT_EQ(isPowerOfThree(x), ans);
    EXPECT_EQ(isPowerOfThree1(x), ans);
}

TEST(case_4, content)
{
    int x = 27;
    bool ans = true;
    EXPECT_EQ(isPowerOfThree(x), ans);
    EXPECT_EQ(isPowerOfThree1(x), ans);
}

TEST(case_5, content)
{
    int x = 8;
    bool ans = false;
    EXPECT_EQ(isPowerOfThree(x), ans);
    EXPECT_EQ(isPowerOfThree1(x), ans);
}