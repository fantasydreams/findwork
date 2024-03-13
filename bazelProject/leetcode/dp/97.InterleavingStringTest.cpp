#include "gtest/gtest.h"
#include "97.InterleavingString.h"

TEST(case_1, content) {
    std::string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    bool ans = true;
    EXPECT_EQ(isInterleave(s1, s2, s3), ans);
    EXPECT_EQ(isInterleave1(s1, s2, s3), ans);
}

TEST(case_2, content) {
    std::string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    bool ans = false;
    EXPECT_EQ(isInterleave(s1, s2, s3), ans);
    EXPECT_EQ(isInterleave1(s1, s2, s3), ans);
}


TEST(case_3, content) {
    std::string s1 = "", s2 = "", s3 = "";
    bool ans = true;
    EXPECT_EQ(isInterleave(s1, s2, s3), ans);
    EXPECT_EQ(isInterleave1(s1, s2, s3), ans);
}


TEST(case_4, content) {
    std::string s1 = "1", s2 = "", s3 = "";
    bool ans = false;
    EXPECT_EQ(isInterleave(s1, s2, s3), ans);
    EXPECT_EQ(isInterleave1(s1, s2, s3), ans);
}