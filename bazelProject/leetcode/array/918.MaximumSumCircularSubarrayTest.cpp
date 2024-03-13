#include "918.MaximumSumCircularSubarray.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    std::vector<int> vec = {1,-2,3,-2};
    int iAns = 3;
    EXPECT_EQ(maxSubarraySumCircular(vec), iAns);
}


TEST(case2, content) {
    std::vector<int> vec = {5,-3,5};
    int iAns = 10;
    EXPECT_EQ(maxSubarraySumCircular(vec), iAns);
}


TEST(case3, content) {
    std::vector<int> vec = {3,-2,2,-3};
    int iAns = 3;
    EXPECT_EQ(maxSubarraySumCircular(vec), iAns);
}


TEST(case4, content) {
    std::vector<int> vec = {-1,3,-3,9,-6,8,-5,-5,-6,10};
    int iAns = 20;
    EXPECT_EQ(maxSubarraySumCircular(vec), iAns);
}