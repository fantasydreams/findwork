#include "228.SummaryRanges.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    std::vector<int> vecNum;
    std::vector<std::string> vecAns = {};
    EXPECT_EQ(summaryRanges(vecNum), vecAns);
    EXPECT_EQ(summaryRanges1(vecNum), vecAns);
}


TEST(case2, content) {
    std::vector<int> vecNum = {0,1,2,4,5,7};
    std::vector<std::string> vecAns = {"0->2","4->5","7"};
    EXPECT_EQ(summaryRanges(vecNum), vecAns);
    EXPECT_EQ(summaryRanges1(vecNum), vecAns);
}


TEST(case3, content) {
    std::vector<int> vecNum = {0,2,3,4,6,8,9};
    std::vector<std::string> vecAns = {"0","2->4","6","8->9"};
    EXPECT_EQ(summaryRanges(vecNum), vecAns);
    EXPECT_EQ(summaryRanges1(vecNum), vecAns);
}

TEST(case4, content) {
    std::vector<int> vecNum = {0};
    std::vector<std::string> vecAns = {"0"};
    EXPECT_EQ(summaryRanges(vecNum), vecAns);
    EXPECT_EQ(summaryRanges1(vecNum), vecAns);
}



TEST(case5, content) {
    std::vector<int> vecNum = {0,1};
    std::vector<std::string> vecAns = {"0->1"};
    EXPECT_EQ(summaryRanges(vecNum), vecAns);
    EXPECT_EQ(summaryRanges1(vecNum), vecAns);
}

TEST(case6, content) {
    std::vector<int> vecNum = {0,1,2};
    std::vector<std::string> vecAns = {"0->2"};
    EXPECT_EQ(summaryRanges(vecNum), vecAns);
    EXPECT_EQ(summaryRanges1(vecNum), vecAns);
}

TEST(case7, content) {
    std::vector<int> vecNum = {0,1,2, 4};
    std::vector<std::string> vecAns = {"0->2", "4"};
    EXPECT_EQ(summaryRanges(vecNum), vecAns);
    EXPECT_EQ(summaryRanges1(vecNum), vecAns);
}


TEST(case8, content) {
    std::vector<int> vecNum = {-1};
    std::vector<std::string> vecAns = {"-1",};
    EXPECT_EQ(summaryRanges(vecNum), vecAns);
    EXPECT_EQ(summaryRanges1(vecNum), vecAns);
}