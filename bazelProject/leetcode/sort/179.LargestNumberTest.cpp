#include "179.LargestNumber.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> vec = {10,2};
    std::string ans = "210";
    EXPECT_EQ(largestNumber(vec), ans);
}


TEST(case_2, content) {
    std::vector<int> vec = {3,30,34,5,9};
    std::string ans = "9534330";
    EXPECT_EQ(largestNumber(vec), ans);
}

TEST(case_3, content) {
    std::vector<int> vec = {432,43243};
    std::string ans = "43243432";
    EXPECT_EQ(largestNumber(vec), ans);
}


TEST(case_4, content) {
    std::vector<int> vec = {0, 0};
    std::string ans = "0";
    EXPECT_EQ(largestNumber(vec), ans);
}
