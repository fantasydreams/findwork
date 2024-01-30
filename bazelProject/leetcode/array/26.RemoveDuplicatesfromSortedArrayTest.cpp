#include "26.RemoveDuplicatesfromSortedArray.h"
#include "gtest/gtest.h"

bool checkinSame(const std::vector<int>& a, const std::vector<int>& b) {
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

TEST(case_1,content)
{
    std::vector<int> height = {1,1,2};
    std::vector<int> vecAns = {1,2};
    EXPECT_EQ(removeDuplicates(height), vecAns.size());
    EXPECT_EQ(checkinSame(vecAns, height), true);
}

TEST(case_2,content)
{
    std::vector<int> height = {0,0,1,1,1,2,2,3,3,4};
    std::vector<int> vecAns = {0,1,2,3,4};
    EXPECT_EQ(removeDuplicates(height), vecAns.size());
    EXPECT_EQ(checkinSame(vecAns, height), true);
}

TEST(case_3,content)
{
    std::vector<int> height = {1,1,2};
    std::vector<int> vecAns = {1,2};
    EXPECT_EQ(removeDuplicates1(height), vecAns.size());
    EXPECT_EQ(checkinSame(vecAns, height), true);
}

TEST(case_4,content)
{
    std::vector<int> height = {0,0,1,1,1,2,2,3,3,4};
    std::vector<int> vecAns = {0,1,2,3,4};
    EXPECT_EQ(removeDuplicates1(height), vecAns.size());
    EXPECT_EQ(checkinSame(vecAns, height), true);
}


TEST(case_5,content)
{
    std::vector<int> height = {1,1,2};
    std::vector<int> vecAns = {1,2};
    EXPECT_EQ(removeDuplicates2(height), vecAns.size());
    EXPECT_EQ(checkinSame(vecAns, height), true);
}

TEST(case_6,content)
{
    std::vector<int> height = {0,0,1,1,1,2,2,3,3,4};
    std::vector<int> vecAns = {0,1,2,3,4};
    EXPECT_EQ(removeDuplicates2(height), vecAns.size());
    EXPECT_EQ(checkinSame(vecAns, height), true);
}

TEST(case_7,content)
{
    std::vector<int> height = {1,1,2};
    std::vector<int> vecAns = {1,2};
    EXPECT_EQ(removeDuplicates2(height), vecAns.size());
    EXPECT_EQ(checkinSame(vecAns, height), true);
}

TEST(case_8,content)
{
    std::vector<int> height = {0,0,1,1,1,2,2,3,3,4};
    std::vector<int> vecAns = {0,1,2,3,4};
    EXPECT_EQ(removeDuplicates2(height), vecAns.size());
    EXPECT_EQ(checkinSame(vecAns, height), true);
}