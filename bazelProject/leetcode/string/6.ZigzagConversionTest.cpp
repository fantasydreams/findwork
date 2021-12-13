#include "gtest/gtest.h"
#include "6.ZigzagConversion.h"

TEST(case_1,content)
{
	  std::string str = "";
    std::string res = "";
    EXPECT_EQ(convert(str, 1), res);
}


TEST(case_2,content)
{
	  std::string str = "PAYPALISHIRING";
    std::string res = "PAHNAPLSIIGYIR";
    EXPECT_EQ(convert(str, 3), res);
}

TEST(case_3,content)
{
	  std::string str = "PAYPALISHIRING";
    std::string res = "PINALSIGYAHRPI";
    EXPECT_EQ(convert(str, 4), res);
}

TEST(case_4,content)
{
	  std::string str = "A";
    std::string res = "A";
    EXPECT_EQ(convert(str, 4), res);
}

TEST(case_5,content)
{
	  std::string str = "AB";
    std::string res = "AB";
    EXPECT_EQ(convert(str, 1), res);
}



int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}