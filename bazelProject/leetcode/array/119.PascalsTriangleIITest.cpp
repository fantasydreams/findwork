#include "gtest/gtest.h"
#include "119.PascalsTriangleII.h"

TEST(case_1, content) {
    int row = 0;
    std::vector<int> ans = {1};

    EXPECT_EQ(getRow(row), ans);
}


TEST(case_2, content) {
    int row = 1;
    std::vector<int> ans = {1,1};

    EXPECT_EQ(getRow(row), ans);
}

TEST(case_3, content) {
    int row = 2;
    std::vector<int> ans = {1,2,1};

    EXPECT_EQ(getRow(row), ans);
}

TEST(case_4, content) {
    int row = 3;
    std::vector<int> ans = {1,3,3,1};

    EXPECT_EQ(getRow(row), ans);
}

TEST(case_5, content) {
    int row = 4;
    std::vector<int> ans = {1,4,6,4,1};

    EXPECT_EQ(getRow(row), ans);
}
