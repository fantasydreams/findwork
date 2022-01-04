#include "1009.ComplementofBase10Integer.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    EXPECT_EQ(bitwiseComplement(1), 0);
}

TEST(case_2,content)
{
    EXPECT_EQ(bitwiseComplement(0), 1);
    EXPECT_EQ(bitwiseComplementSimple(0), 1);
}

TEST(case_3,content)
{
    EXPECT_EQ(bitwiseComplement(5), 2);
    EXPECT_EQ(bitwiseComplementSimple(5), 2);
}

TEST(case_4,content)
{
    EXPECT_EQ(bitwiseComplement(7), 0);
    EXPECT_EQ(bitwiseComplementSimple(7), 0);
}


TEST(case_5,content)
{
    EXPECT_EQ(bitwiseComplement(10), 5);
    EXPECT_EQ(bitwiseComplementSimple(10), 5);
}


int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}