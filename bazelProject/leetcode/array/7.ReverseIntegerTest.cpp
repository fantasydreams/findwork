#include "gtest/gtest.h"
#include "7.ReverseInteger.h"

TEST(case_1,content)
{
    EXPECT_EQ(reverse(1), 1);
}

TEST(case_2,content)
{
    EXPECT_EQ(reverse(-1), -1);
}

TEST(case_3,content)
{
    EXPECT_EQ(reverse(-123), -321);
}

TEST(case_4,content)
{
    EXPECT_EQ(reverse(123), 321);
}

TEST(case_5,content)
{
    EXPECT_EQ(reverse(120), 21);
}

TEST(case_6,content)
{
    EXPECT_EQ(reverse(-1231231239), 0);
}

TEST(case_7,content)
{
    EXPECT_EQ(reverse(1231231239), 0);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}