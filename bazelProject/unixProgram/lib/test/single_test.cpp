#include "gtest/gtest.h"

int func(int a, int b) {
    return a + b;
}

TEST(mode_test_1, content)
{
    EXPECT_EQ(func(1,1), 2);
}