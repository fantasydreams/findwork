#include "52.N-QueensII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int n = 4;
    int ans = 2;
    EXPECT_EQ(totalNQueens(n), ans);
}

TEST(case_2,content)
{
    int n = 1;
    int ans = 1;
    EXPECT_EQ(totalNQueens(n), ans);
}
