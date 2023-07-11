#include "17.LetterCombinationsofaPhoneNumber.h"

#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<std::string> ans = {};
    std::string sDigits = "";
    EXPECT_EQ(letterCombinations(sDigits), ans);
}


TEST(case_2,content)
{
    std::vector<std::string> ans = {};
    std::string sDigits = "01";
    EXPECT_EQ(letterCombinations(sDigits), ans);
}

TEST(case_3,content)
{
    std::vector<std::string> ans = {};
    std::string sDigits = "01";
    EXPECT_EQ(letterCombinations(sDigits), ans);
}

TEST(case_4,content)
{
    std::vector<std::string> ans = {"a","b","c"};
    std::string sDigits = "02";
    EXPECT_EQ(letterCombinations(sDigits), ans);
}

TEST(case_5,content)
{
    std::vector<std::string> ans = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
    std::string sDigits = "23";
    EXPECT_EQ(letterCombinations(sDigits), ans);
}

