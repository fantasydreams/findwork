#include "216.CombinationSumIII.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int k = 3, n = 7;
    std::vector<std::vector<int> > vecAns = {{1,2,4}};
    EXPECT_EQ(combinationSum3(k, n), vecAns);
}


TEST(case_2, content) {
    int k = 3, n = 9;
    std::vector<std::vector<int> > vecAns = {
        {1,2,6},
        {1,3,5},
        {2,3,4}
        };
    EXPECT_EQ(combinationSum3(k, n), vecAns);
}

TEST(case_3, content) {
    int k = 9, n = 45;
    std::vector<std::vector<int> > vecAns = {
        {1,2,3,4,5,6,7,8,9},
        };
    EXPECT_EQ(combinationSum3(k, n), vecAns);
}