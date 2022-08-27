#include "gtest/gtest.h"
#include "12.IntegerToRoman.h"

TEST(case_1,content)
{
    EXPECT_EQ(intToRoman(1), "I");
}

TEST(case_2,content)
{
    EXPECT_EQ(intToRoman(2), "II");
}

TEST(case_3,content)
{
    EXPECT_EQ(intToRoman(3), "III");
}

TEST(case_4,content)
{
    EXPECT_EQ(intToRoman(4), "IV");
}

TEST(case_5,content)
{
    EXPECT_EQ(intToRoman(5), "V");
}

TEST(case_6,content)
{
    EXPECT_EQ(intToRoman(400), "CD");
}

TEST(case_7,content)
{
    EXPECT_EQ(intToRoman(58), "LVIII");
}


TEST(case_8,content)
{
    EXPECT_EQ(intToRoman(1994), "MCMXCIV");
}
int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}