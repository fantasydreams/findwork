#include "162.FindPeakElement.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int ans = 2;
    std::vector<int> vec = {1,2,3,1};
    EXPECT_EQ(findPeakElement(vec), ans);
    EXPECT_EQ(findPeakElement1(vec), ans);
}


TEST(case_2, content) {
    int ans = 1;
    std::vector<int> vec = {1,2,1,3,5,6,4};
    EXPECT_EQ(findPeakElement(vec), ans);
    EXPECT_EQ(findPeakElement1(vec), ans);
}


TEST(case_3, content) {
    int ans = 0;
    std::vector<int> vec = {1};
    EXPECT_EQ(findPeakElement(vec), ans);
    EXPECT_EQ(findPeakElement1(vec), ans);
}