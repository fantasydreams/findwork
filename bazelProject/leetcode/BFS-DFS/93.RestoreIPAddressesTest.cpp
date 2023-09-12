#include "93.RestoreIPAddresses.h"
#include "gtest/gtest.h"
#include <string>

TEST(case_1, content)
{
    std::string s = "0000";
    std::vector<std::string> ans = {"0.0.0.0"};
    
    EXPECT_EQ(restoreIpAddresses(s), ans);
}

TEST(case_2, content)
{
    std::string s = "101023";
    std::vector<std::string> ans = {"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"};
    
    EXPECT_EQ(restoreIpAddresses(s), ans);
}

TEST(case_3, content)
{
    std::string s = "25525511135";
    std::vector<std::string> ans = {"255.255.11.135","255.255.111.35"};
    
    EXPECT_EQ(restoreIpAddresses(s), ans);
}