#include "13.RomantoInteger.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::string sroman = "III";
    int res = 3;
    EXPECT_EQ(romanToInt(sroman), res);
    EXPECT_EQ(romanToInt1(sroman), res);
    EXPECT_EQ(romanToInt2(sroman), res);
}

TEST(case_2,content)
{
    std::string sroman = "LVIII";
    int res = 58;
    EXPECT_EQ(romanToInt(sroman), res);
    EXPECT_EQ(romanToInt1(sroman), res);
    EXPECT_EQ(romanToInt2(sroman), res);
}


TEST(case_3,content)
{
    std::string sroman = "MCMXCIV";
    int res = 1994;
    EXPECT_EQ(romanToInt(sroman), res);
    EXPECT_EQ(romanToInt1(sroman), res);
    EXPECT_EQ(romanToInt2(sroman), res);
}



int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
