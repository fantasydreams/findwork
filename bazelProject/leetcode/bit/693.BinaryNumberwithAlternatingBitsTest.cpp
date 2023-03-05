#include "693.BinaryNumberwithAlternatingBits.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    int num = 5;
    bool ans = true;
    EXPECT_EQ(hasAlternatingBits(num), ans);
}

TEST(case_2,content)
{
    int num = 7;
    bool ans = false;
    EXPECT_EQ(hasAlternatingBits(num), ans);
}