#include "476.NumberComplement.h"
#include "gtest/gtest.h"
#include <algorithm>


TEST(case_2,content)
{
    int num = 5;
    int ans = 2;
    EXPECT_EQ(findComplement(num), ans);
}

TEST(case_3,content)
{
    int num = 1;
    int ans = 0;
    EXPECT_EQ(findComplement(num), ans);
}