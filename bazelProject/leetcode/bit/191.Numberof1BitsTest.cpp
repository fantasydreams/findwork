#include "191.Numberof1Bits.h"
#include "gtest/gtest.h"
#include <cstdint>

TEST(case_1, content) {
    uint32_t num = 5;
    int ans = 2;
    EXPECT_EQ(hammingWeight(num), ans);
}


TEST(case_2, content) {
    uint32_t num = 7;
    int ans = 3;
    EXPECT_EQ(hammingWeight(num), ans);
}


TEST(case_3, content) {
    uint32_t num = UINT32_MAX;
    int ans = 32;
    EXPECT_EQ(hammingWeight(num), ans);
}