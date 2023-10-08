#include "126.WordLadderII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::vector<std::vector<std::string>> ans = {{"hit","hot","dot","dog","cog"}, {"hit","hot","lot","log","cog"}};
    EXPECT_EQ(findLadders(beginWord, endWord, wordList), ans);
    EXPECT_EQ(findLadders1(beginWord, endWord, wordList), ans);
    EXPECT_EQ(findLaddersAdj(beginWord, endWord, wordList), ans); 
}

TEST(case_2,content)
{
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log"};
    std::vector<std::vector<std::string>> ans = {};
    EXPECT_EQ(findLadders(beginWord, endWord, wordList), ans);
    EXPECT_EQ(findLadders1(beginWord, endWord, wordList), ans);
    EXPECT_EQ(findLaddersAdj(beginWord, endWord, wordList), ans);
}