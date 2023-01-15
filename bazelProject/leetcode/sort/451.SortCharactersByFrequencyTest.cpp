#include "451.SortCharactersByFrequency.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string src = "tree";
    std::string res = "eert";
    EXPECT_EQ(frequencySort(src), res);
}

TEST(case_2,content)
{
    std::string src = "cccaaa";
    std::string res = "aaaccc";
    EXPECT_EQ(frequencySort(src), res);
}

TEST(case_3,content)
{
    std::string src = "abbcccdddd";
    std::string res = "ddddcccbba";
    EXPECT_EQ(frequencySort(src), res);
}