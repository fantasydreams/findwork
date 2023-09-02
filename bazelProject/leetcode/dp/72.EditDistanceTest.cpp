#include "72.EditDistance.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string word1 = "horse", word2 = "ros";
    int ans = 3;
    EXPECT_EQ(minDistance(word1, word2), ans);
    EXPECT_EQ(minDistanceDp(word1, word2), ans);
}

TEST(case_2,content)
{
    std::string word1 = "intention", word2 = "execution";
    int ans = 5;
    EXPECT_EQ(minDistance(word1, word2), ans);
    EXPECT_EQ(minDistanceDp(word1, word2), ans);
}