#include "304.RangeSumQuery2D-Immutable.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix m(matrix);

    EXPECT_EQ(m.sumRegion(2, 1, 4, 3), 8);
    EXPECT_EQ(m.sumRegion(1, 1, 2, 2), 11);
    EXPECT_EQ(m.sumRegion(1, 2, 2, 4), 12);
}