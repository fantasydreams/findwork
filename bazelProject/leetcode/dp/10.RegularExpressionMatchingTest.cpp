#include "10.RegularExpressionMatching.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string str = "aa", partten = "a";
    bool ans = false;
    EXPECT_EQ(isMatch(str, partten), ans);
    EXPECT_EQ(isMatch1(str, partten), ans);
}

TEST(case_2,content)
{
    std::string str = "aa", partten = "a*";
    bool ans = true;
    EXPECT_EQ(isMatch(str, partten), ans);
    EXPECT_EQ(isMatch1(str, partten), ans);
}

TEST(case_3,content)
{
    std::string str = "aab", partten = "c*a*b*";
    bool ans = true;
    EXPECT_EQ(isMatch(str, partten), ans);    
    EXPECT_EQ(isMatch1(str, partten), ans);    
}


TEST(case_4,content)
{
    std::string str = "aab", partten = "c*a*b";
    bool ans = true;
    EXPECT_EQ(isMatch(str, partten), ans);    
    EXPECT_EQ(isMatch1(str, partten), ans);    
}


TEST(case_5,content)
{
    std::string str = "mississippi", partten = "mis*is*p*.";
    bool ans = false;
    EXPECT_EQ(isMatch(str, partten), ans);    
    EXPECT_EQ(isMatch1(str, partten), ans);    
}