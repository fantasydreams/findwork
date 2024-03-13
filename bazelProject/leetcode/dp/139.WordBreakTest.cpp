#include "139.WordBreak.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string word = "leetcode";
    std::vector<std::string> wordDict = {"leet","code"};
    bool ans = true;
    EXPECT_EQ(wordBreak(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp1(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp2(word, wordDict), ans);
}


TEST(case_2,content)
{
    std::string word = "applepenapple";
    std::vector<std::string> wordDict = {"apple","pen"};
    bool ans = true;
    EXPECT_EQ(wordBreak(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp1(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp2(word, wordDict), ans);
}

TEST(case_3,content)
{
    std::string word = "catsandog";
    std::vector<std::string> wordDict = {"cats","dog","sand","and","cat"};
    bool ans = false;
    EXPECT_EQ(wordBreak(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp1(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp2(word, wordDict), ans);
}

TEST(case_4,content)
{
    std::string word = "a";
    std::vector<std::string> wordDict = {"b"};
    bool ans = false;
    EXPECT_EQ(wordBreak(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp1(word, wordDict), ans);
    EXPECT_EQ(wordBreakDp2(word, wordDict), ans);
}