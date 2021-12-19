#include "8.StringtoInteger(atoi).h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    EXPECT_EQ(myAtoi("-1"), -1);
}

TEST(case_2,content)
{
    EXPECT_EQ(myAtoi("10"), 10);
}

TEST(case_3,content)
{
    EXPECT_EQ(myAtoi("-0210"), -210);
}

TEST(case_4,content)
{
    EXPECT_EQ(myAtoi("   -0210"), -210);
}


TEST(case_5,content)
{
    EXPECT_EQ(myAtoi("   -0210.123"), -210);
}

TEST(case_6,content)
{
    EXPECT_EQ(myAtoi("   -"), 0);
}

TEST(case_7,content)
{
    EXPECT_EQ(myAtoi(" 123.432-"), 123);
}


TEST(case_8,content)
{
    EXPECT_EQ(myAtoi1(" --+123.432-"), 123);
    EXPECT_EQ(myAtoi(" +-123.432-"), 0);
}


TEST(case_9,content)
{
    EXPECT_EQ(myAtoi1(" -+123.432-"), -123);
    EXPECT_EQ(myAtoi(" -+123.432-"), 0);
}

TEST(case_10,content)
{
    EXPECT_EQ(myAtoi(" 2147483647"), 2147483647);
}

TEST(case_11,content)
{
    EXPECT_EQ(myAtoi(" 2147483648"), 2147483647);
}

TEST(case_12,content)
{
    EXPECT_EQ(myAtoi(" -2147483648"), -2147483648);
}

TEST(case_13,content)
{
    EXPECT_EQ(myAtoi(" -2147483649"), -2147483648);
}


int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

