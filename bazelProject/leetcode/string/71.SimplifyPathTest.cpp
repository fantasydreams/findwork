#include "71.SimplifyPath.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::string sPath = "/home/";
    std::string sAns = "/home";
    EXPECT_EQ(simplifyPath(sPath), sAns);
    EXPECT_EQ(simplifyPath1(sPath), sAns);
    EXPECT_EQ(simplifyPath2(sPath), sAns);
}

TEST(case_2, content)
{
    std::string sPath = "/../";
    std::string sAns = "/";
    EXPECT_EQ(simplifyPath(sPath), sAns);
    EXPECT_EQ(simplifyPath1(sPath), sAns);
    EXPECT_EQ(simplifyPath2(sPath), sAns);
}

TEST(case_3, content)
{
    std::string sPath = "/home//foo/";
    std::string sAns = "/home/foo";
    EXPECT_EQ(simplifyPath(sPath), sAns);
    EXPECT_EQ(simplifyPath1(sPath), sAns);
    EXPECT_EQ(simplifyPath2(sPath), sAns);
}