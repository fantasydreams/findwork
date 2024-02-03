#include "392.IsSubsequence.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::string s = "abc", t = "ahbgdc";
    bool bAns = true;
    EXPECT_EQ(isSubsequence(s, t), bAns);
}


TEST(case_2, content) {
    std::string s = "axc", t = "ahbgdc";
    bool bAns = false;
    EXPECT_EQ(isSubsequence(s, t), bAns);
}