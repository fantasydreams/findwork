#include "223.RectangleArea.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    int ans = 45;
    EXPECT_EQ(computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2), ans);
}


TEST(case_2, content) {
    int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;
    int ans = 16;
    EXPECT_EQ(computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2), ans);
}