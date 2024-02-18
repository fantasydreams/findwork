#include "290.WordPattern.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::string pattern = "abba", s = "dog cat cat dog";
    bool bAns = true;
    EXPECT_EQ(wordPattern(pattern, s), bAns);
}


TEST(case_2, content) {
    std::string pattern = "abba", s = "dog cat cat fish";
    bool bAns = false;
    EXPECT_EQ(wordPattern(pattern, s), bAns);
}

TEST(case_3, content) {
    std::string pattern = "aaaa", s = "dog cat cat dog";
    bool bAns = false;
    EXPECT_EQ(wordPattern(pattern, s), bAns);
}

TEST(case_4, content) {
    std::string pattern = "abba", s = "dog dog dog dog";
    bool bAns = false;
    EXPECT_EQ(wordPattern(pattern, s), bAns);
}