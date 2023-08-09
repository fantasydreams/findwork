#include "35.SearchInsertPosition.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int target = 2, ans = 1;
    std::vector<int> vec1 = {1,2,3};
    EXPECT_EQ(searchInsert(vec1, target), ans);
    EXPECT_EQ(searchInsertStl(vec1, target), ans);
}


TEST(case_2,content)
{
    int target = 5, ans = 2;
    std::vector<int> vec1 = {1,3,5,6};
    EXPECT_EQ(searchInsert(vec1, target), ans);
    EXPECT_EQ(searchInsertStl(vec1, target), ans);
}


TEST(case_3,content)
{
    int target = 2, ans = 1;
    std::vector<int> vec1 = {1,3,5,6};
    EXPECT_EQ(searchInsert(vec1, target), ans);
    EXPECT_EQ(searchInsertStl(vec1, target), ans);
}


TEST(case_4,content)
{
    int target = 7, ans = 4;
    std::vector<int> vec1 = {1,3,5,6};
    EXPECT_EQ(searchInsert(vec1, target), ans);
    EXPECT_EQ(searchInsertStl(vec1, target), ans);
}