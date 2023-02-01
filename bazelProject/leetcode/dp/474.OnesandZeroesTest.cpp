#include "474.OnesandZeroes.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<std::string> strs = {"10","0001","111001","1","0"};
    int ans = 4, m = 5, n = 3;
    EXPECT_EQ(findMaxForm(strs, m, n), ans);
}

TEST(case_2,content)
{
    std::vector<std::string> strs = {"10","0","1"};
    int ans = 2, m = 1, n = 1;
    EXPECT_EQ(findMaxForm(strs, m, n), ans);
}

TEST(case_3,content)
{
    std::vector<std::string> strs = {"10","0","1"};
    int ans = 3, m = 2, n = 2;
    EXPECT_EQ(findMaxForm(strs, m, n), ans);
}

TEST(case_4, content)
{
    std::vector<std::string> strs = {"10","0","1"};
    int ans = 3, m = 3, n = 2;
    EXPECT_EQ(findMaxForm(strs, m, n), ans);
}