#include "30.SubstringwithConcatenationofAllWords.h"
#include "gtest/gtest.h"
#include <string>


TEST(case_1,content)
{
    std::string s = "barfoothefoobarman";
    std::vector<std::string> words = {"foo","bar"};
    std::vector<int> ans = {0,9};
    
    EXPECT_EQ(findSubstring(s, words), ans);
    EXPECT_EQ(findSubstringWindow(s, words), ans);
}


TEST(case_2, content)
{
    std::string s = "wordgoodgoodgoodbestword";
    std::vector<std::string> words = {"word","good","best","word"};
    std::vector<int> ans = {};
    
    EXPECT_EQ(findSubstring(s, words), ans);
    EXPECT_EQ(findSubstringWindow(s, words), ans);
}

TEST(case_3, content)
{
    std::string s = "barfoofoobarthefoobarman";
    std::vector<std::string> words = {"bar","foo","the"};
    std::vector<int> ans = {6,9,12};
    
    EXPECT_EQ(findSubstring(s, words), ans);
    EXPECT_EQ(findSubstringWindow(s, words), ans);
}

TEST(case_4, content)
{
    std::string s = "wordgoodgoodgoodbestword";
    std::vector<std::string> words = {"word","good","best","good"};
    std::vector<int> ans = {8};
    
    EXPECT_EQ(findSubstring(s, words), ans);
    EXPECT_EQ(findSubstringWindow(s, words), ans);
}