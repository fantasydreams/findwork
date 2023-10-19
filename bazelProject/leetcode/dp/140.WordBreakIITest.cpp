#include "140.WordBreakII.h"
#include "gtest/gtest.h"
#include <string>

TEST(case_1, content) {
    std::string s = "catsanddog";
    std::vector<std::string> wordDict = {"cat","cats","and","sand","dog"};
    std::vector<std::string> ans = {"cats and dog","cat sand dog"};
    std::sort(ans.begin(), ans.end());
    std::vector<std::string> realans = wordBreak(s, wordDict);
    std::sort(realans.begin(), realans.end()); 
    EXPECT_EQ(realans, ans);
}


TEST(case_2, content) {
    std::string s = "pineapplepenapple";
    std::vector<std::string> wordDict = {"apple","pen","applepen","pine","pineapple"};
    std::vector<std::string> ans = {"pine apple pen apple","pineapple pen apple","pine applepen apple"};
    std::sort(ans.begin(), ans.end());
    std::vector<std::string> realans = wordBreak(s, wordDict);
    std::sort(realans.begin(), realans.end()); 
    EXPECT_EQ(wordBreak(s, wordDict), ans);
}

TEST(case_3, content) {
    std::string s = "catsandog";
    std::vector<std::string> wordDict = {"cats","dog","sand","and","cat"};
    std::vector<std::string> ans = {};
    std::sort(ans.begin(), ans.end());
    std::vector<std::string> realans = wordBreak(s, wordDict);
    std::sort(realans.begin(), realans.end()); 
    EXPECT_EQ(wordBreak(s, wordDict), ans);
}