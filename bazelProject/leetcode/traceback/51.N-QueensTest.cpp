#include "51.N-Queens.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int n = 4;
    vector<vector<string>> res = {{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}};
    EXPECT_EQ(solveNQueens(n), res);
}

TEST(case_2,content)
{
    int n = 1;
    vector<vector<string>> res = {{"Q"}};
    EXPECT_EQ(solveNQueens(n), res);
}