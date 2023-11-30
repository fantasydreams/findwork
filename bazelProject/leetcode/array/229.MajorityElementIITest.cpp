#include "229.MajorityElementII.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> vecNums = {3,2,3};
    std::vector<int> vecAns = {3};
    EXPECT_EQ(majorityElement(vecNums), vecAns);
    EXPECT_EQ(majorityElement1(vecNums), vecAns);
}


TEST(case_2, content) {
    std::vector<int> vecNums = {1};
    std::vector<int> vecAns = {1};
    EXPECT_EQ(majorityElement(vecNums), vecAns);
    EXPECT_EQ(majorityElement1(vecNums), vecAns);
}

TEST(case_3, content) {
    std::vector<int> vecNums = {1,2};
    std::vector<int> vecAns = {1,2};
    std::vector<int> vecRet = majorityElement(vecNums);
    std::sort(vecRet.begin(), vecRet.end());
    EXPECT_EQ(vecRet, vecAns);
    EXPECT_EQ(majorityElement1(vecNums), vecAns);
}