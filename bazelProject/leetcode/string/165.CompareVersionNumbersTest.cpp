#include "165.CompareVersionNumbers.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int ans = 0;
    std::string version1 = "1.01", version2 = "1.001";
    EXPECT_EQ(compareVersion(version1, version2), ans);
    EXPECT_EQ(compareVersion1(version1, version2), ans);
}


TEST(case_2, content) {
    int ans = 0;
    std::string version1 = "1.0", version2 = "1.0.0";
    EXPECT_EQ(compareVersion(version1, version2), ans);
    EXPECT_EQ(compareVersion1(version1, version2), ans);
}

TEST(case_3, content) {
    int ans = -1;
    std::string version1 = "0.1", version2 = "1.1";
    EXPECT_EQ(compareVersion(version1, version2), ans);
    EXPECT_EQ(compareVersion1(version1, version2), ans);
}

TEST(case_4, content) {
    int ans = 1;
    std::string version1 = "1.1.0", version2 = "1.0";
    EXPECT_EQ(compareVersion(version1, version2), ans);
    EXPECT_EQ(compareVersion1(version1, version2), ans);
}


TEST(case_5, content) {
    int ans = 1;
    std::string version1 = "1.0.1", version2 = "1";
    EXPECT_EQ(compareVersion(version1, version2), ans);
    EXPECT_EQ(compareVersion1(version1, version2), ans);
}


TEST(case_6, content) {
    int ans = -1;
    std::string version1 = "1", version2 = "1.0.1";
    EXPECT_EQ(compareVersion(version1, version2), ans);
    EXPECT_EQ(compareVersion1(version1, version2), ans);
}