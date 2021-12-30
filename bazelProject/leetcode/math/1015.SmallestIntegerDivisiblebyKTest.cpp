#include "gtest/gtest.h"
#include "1015.SmallestIntegerDivisiblebyK.h"

TEST(case_1,content)
{
    EXPECT_EQ(smallestRepunitDivByK(1), 1);
}

TEST(case_2,content)
{
    EXPECT_EQ(smallestRepunitDivByK(2), -1);
}

TEST(case_3,content)
{
    EXPECT_EQ(smallestRepunitDivByK(3), 3);
}



int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}