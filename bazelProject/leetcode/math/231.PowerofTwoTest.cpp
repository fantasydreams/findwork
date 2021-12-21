#include "231.PowerofTwo.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    EXPECT_EQ(isPowerOfTwo(1), true);
    EXPECT_EQ(isPowerOfTwo1(1), true);
}

TEST(case_2,content)
{
    EXPECT_EQ(isPowerOfTwo(0), false);
    EXPECT_EQ(isPowerOfTwo1(0), false);
}

TEST(case_3,content)
{
    EXPECT_EQ(isPowerOfTwo(3), false);
    EXPECT_EQ(isPowerOfTwo1(3), false);
}

TEST(case_4,content)
{
    EXPECT_EQ(isPowerOfTwo(8), true);
    EXPECT_EQ(isPowerOfTwo1(8), true);
}



int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}