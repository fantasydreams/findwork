#include "189.RotateArray.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int k = 3;
    std::vector<int> vec = {1,2,3,4,5,6,7};
    std::vector<int> ans = {5,6,7,1,2,3,4};
    rotate(vec, k);
    EXPECT_EQ(vec, ans);
}

TEST(case_2, content) {
    int k = 2;
    std::vector<int> vec = {-1,-100,3,99};
    std::vector<int> ans = {3,99,-1,-100};
    rotate(vec, k);
    EXPECT_EQ(vec, ans);
}


TEST(case_3, content) {
    int k = 4;
    std::vector<int> vec = {-1,-100,3,99};
    std::vector<int> ans = {-1,-100,3,99};
    rotate(vec, k);
    EXPECT_EQ(vec, ans);
}

TEST(case_4, content) {
    int k = 1;
    std::vector<int> vec = {-1,-100,3,99};
    std::vector<int> ans = {99, -1, -100, 3};
    rotate(vec, k);
    EXPECT_EQ(vec, ans);
}


TEST(case_5, content) {
    int k = 3;
    std::vector<int> vec = {-1,-100,3,99};
    std::vector<int> ans = {-100, 3, 99, -1};
    rotate(vec, k);
    EXPECT_EQ(vec, ans);
}