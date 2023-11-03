#include "190.ReverseBits.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    uint32_t x = 43261596, ans = 964176192;
    EXPECT_EQ(reverseBits(x), ans);
    EXPECT_EQ(reverseBits1(x),ans);
}