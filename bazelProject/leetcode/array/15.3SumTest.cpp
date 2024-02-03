#include "15.3Sum.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> vec = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int> > vecAns = {
        {-1,-1,2},
        {-1,0,1}
    };

    EXPECT_EQ(threeSum(vec), vecAns);
}

TEST(case_2, content) {
    std::vector<int> vec = {0,1,1};
    std::vector<std::vector<int> > vecAns = {};
    
    EXPECT_EQ(threeSum(vec), vecAns);
}


TEST(case_3, content) {
    std::vector<int> vec = {0,0,0};
    std::vector<std::vector<int> > vecAns = {{0,0,0}};
    
    EXPECT_EQ(threeSum(vec), vecAns);
}


TEST(case_4, content) {
    std::vector<int> vec = {-2,0,1,1,2};
    std::vector<std::vector<int> > vecAns = {{-2,0,2}, {-2,1,1}};
    
    EXPECT_EQ(threeSum(vec), vecAns);
}