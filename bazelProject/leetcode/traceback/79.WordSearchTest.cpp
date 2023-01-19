#include "79.WordSearch.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<vector<char>> res = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word = "ABCCED";
    bool bexsit = true;
    EXPECT_EQ(exist(res, word), bexsit);
}


TEST(case_2,content)
{
    vector<vector<char>> res = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word = "SEE";
    bool bexsit = true;
    EXPECT_EQ(exist(res, word), bexsit);
}

TEST(case_3,content)
{
    vector<vector<char>> res = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word = "ABCB";
    bool bexsit = false;
    EXPECT_EQ(exist(res, word), bexsit);
}