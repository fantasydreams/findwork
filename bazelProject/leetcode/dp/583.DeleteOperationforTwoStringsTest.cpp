#include "583.DeleteOperationforTwoStrings.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string word1 = "sea", word2 = "eat";
    int ans = 2;
    EXPECT_EQ(minDistance(word1, word2), ans);
}

TEST(case_2,content)
{
    std::string word1 = "leetcode", word2 = "etco";
    int ans = 4;
    EXPECT_EQ(minDistance(word1, word2), ans);
}