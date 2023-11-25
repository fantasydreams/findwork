#include "212.WordSearchII.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1, content) {
    std::vector<std::vector<char> > board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    std::vector<std::string> words = {"oath","pea","eat","rain"};
    std::vector<std::string> vecAns = {"eat", "oath"};

    std::sort(vecAns.begin(), vecAns.end());
    std::vector<std::string> vecRet = findWords(board, words);
    std::sort(vecRet.begin(), vecRet.end());
    EXPECT_EQ(vecAns, vecRet);
}


TEST(case_2, content) {
    std::vector<std::vector<char> > board = {{'a','b'},{'c','d'}};
    std::vector<std::string> words = {"abcb"};
    std::vector<std::string> vecAns = {};

    std::vector<std::string> vecRet = findWords(board, words);
    EXPECT_EQ(vecAns, vecRet);
}


TEST(case_3, content) {
    std::vector<std::vector<char> > board = {{'a','a'}};
    std::vector<std::string> words = {"aaa"};
    std::vector<std::string> vecAns = {};

    std::vector<std::string> vecRet = findWords(board, words);
    EXPECT_EQ(vecAns, vecRet);
}