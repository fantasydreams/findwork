#include "769.MaxChunksToMakeSorted.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
   std::vector<int> nums = {1,0,2,3,4};
    int ans = 4;
    EXPECT_EQ(maxChunksToSorted(nums), ans);
}


TEST(case_2,content)
{
   std::vector<int> nums = {4,3,2,1,0};
    int ans = 1;
    EXPECT_EQ(maxChunksToSorted(nums), ans);
}


TEST(case_3,content)
{
   std::vector<int> nums = {4,0,2,1,3,5,7,6,8};
    int ans = 4;
    EXPECT_EQ(maxChunksToSorted(nums), ans);
}

TEST(case_4,content)
{
    std::vector<int> nums = {0,2,1};
    int ans = 2;
    EXPECT_EQ(maxChunksToSorted(nums), ans);
}

TEST(case_5,content)
{
    std::vector<int> nums = {0,2,1,4,3};
    int ans = 3;
    EXPECT_EQ(maxChunksToSorted(nums), ans);
}