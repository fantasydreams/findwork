#include "gtest/gtest.h"
#include "lib/string/stringlib.h"

TEST(str_trim_1, content)
{
    std::string str = "  ,123456789,.-   ";
    std::string expect = "123456789";
    std::string res = stringlib::str_trim(str, " ,.-");
    EXPECT_EQ(res, expect);
}

TEST(str_trim_2, content)
{
    std::string str = "  ,123456789,.-   ";
    std::string expect = "";
    std::string res = stringlib::str_trim(str, "");
    EXPECT_EQ(res, str);
}

TEST(str_trim_3, content)
{
    std::string str = "  ,123456789,.-   ";
    std::string expect = "234578-";
    std::string res = stringlib::str_trim(str, "691., ");
    EXPECT_EQ(res, expect);
}

TEST(str_trim_4, content)
{
    std::string str = "  ,123456789,.-   ";
    std::string expect = str;
    std::string res = stringlib::str_trim(str, "");
    EXPECT_EQ(res, expect);
}

TEST(str_trim_5, content)
{
    std::string str = "   ";
    std::string expect = "";
    std::string res = stringlib::str_trim(str, " ,");
    EXPECT_EQ(res, expect);
}

TEST(str_trim_6, content)
{
    std::string str = "123";
    std::string expect = "123";
    std::string res = stringlib::str_trim(str, " -./'[],");
    EXPECT_EQ(res, expect);
}

TEST(str_trim_7, content)
{
    std::string str = "1234_/[],@#$%";
    std::string expect = "";
    std::string res = stringlib::str_trim(str, str);
    EXPECT_EQ(res, expect);
}

TEST(str_trim_8, content)
{
    std::string str = "sharwentest";
    std::string expect = "sharwntst";
    std::string res = stringlib::str_trim(str, "e");
    EXPECT_EQ(res, expect);
}

TEST(str_split_1, content)
{
    std::string str = "sharwEntest";
    std::vector<std::string> expect = {"sharw","nt","st"};
    std::vector<std::string> res = stringlib::str_split(str, "e", "", false);
    EXPECT_EQ(res, expect);
}

TEST(str_split_2, content)
{
    std::string str = "sharwEntest";
    std::vector<std::string> expect = {"sharwEnt","st"};
    std::vector<std::string> res = stringlib::str_split(str, "e", "", true);
    EXPECT_EQ(res, expect);
}

TEST(str_split_3, content)
{
    std::string str = "shar  wEnte,s,t";
    std::vector<std::string> expect = {"shar","w","nt","s","t"};
    std::vector<std::string> res = stringlib::str_split(str, "E, ", "", false);
    EXPECT_EQ(res, expect);
}

TEST(str_split_4, content)
{
    std::string str = "shar  wEnte,,s,t";
    std::vector<std::string> expect = {"shar  wEnt","s","t"};
    std::vector<std::string> res = stringlib::str_split(str, "e,", "", true);
    EXPECT_EQ(res, expect);
}

TEST(str_split_5, content)
{
    std::string str = "shar  wEnte,,s,t";
    std::vector<std::string> expect = {"sharwEnt","s","t"};
    std::vector<std::string> res = stringlib::str_split(str, "e,", " ", true);
    EXPECT_EQ(res, expect);
}


int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}