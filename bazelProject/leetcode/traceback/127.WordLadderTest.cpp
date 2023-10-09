#include "127.WordLadder.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::vector<std::vector<std::string>> ans = {{"hit","hot","dot","dog","cog"}, {"hit","hot","lot","log","cog"}};
    int res = 5;
    EXPECT_EQ(ladderLength(beginWord, endWord, wordList), res);
    EXPECT_EQ(ladderLength1(beginWord, endWord, wordList), res);
}

TEST(case_2,content)
{
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log"};
    std::vector<std::vector<std::string>> ans = {};
    int res = 0;
    EXPECT_EQ(ladderLength(beginWord, endWord, wordList), res);
    EXPECT_EQ(ladderLength1(beginWord, endWord, wordList), res);
}
