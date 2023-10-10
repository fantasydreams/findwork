#include "132.PalindromePartitioningII.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::string s = "aab";
    int ans = 1;
    EXPECT_EQ(minCut(s), ans);
}


TEST(case_2, content) {
    std::string s = "a";
    int ans = 0;
    EXPECT_EQ(minCut(s), ans);
}

TEST(case_3, content) {
    std::string s = "ab";
    int ans = 1;
    EXPECT_EQ(minCut(s), ans);
}