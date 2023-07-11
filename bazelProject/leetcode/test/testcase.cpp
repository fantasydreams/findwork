#include "code.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    int num;
    EXPECT_EQ(echo(num), num);
}


TEST(case_2, content)
{
    std::string RawStr = "wechat wework wechatwdd";
    std::string strMatch = "wechat";
    std::string strReplace = "ww";
    std::string sRes = "ww wework wwwdd";
    getReplacedString(RawStr, strMatch, strReplace);
    EXPECT_EQ(RawStr, sRes);
}
