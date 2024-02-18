#include "383.RansomNote.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    std::string s = "a", m = "b";
    bool bAns = false;
    EXPECT_EQ(canConstruct(s, m), bAns);
}


TEST(case2, content) {
    std::string s = "aa", m = "ab";
    bool bAns = false;
    EXPECT_EQ(canConstruct(s, m), bAns);
}


TEST(case3, content) {
    std::string s = "aa", m = "aab";
    bool bAns = true;
    EXPECT_EQ(canConstruct(s, m), bAns);
}