#include "416.PartitionEqualSubsetSum.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {1, 5, 5, 11};
    bool ans = true;
    EXPECT_EQ(canPartition(nums), ans);
    EXPECT_EQ(canPartition1(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {1,2,3,5};
    bool ans = false;
    EXPECT_EQ(canPartition(nums), ans);
    EXPECT_EQ(canPartition1(nums), ans);
}

TEST(case_3,content)
{
    std::vector<int> nums = {1,2,5};
    bool ans = false;
    EXPECT_EQ(canPartition(nums), ans);
    EXPECT_EQ(canPartition1(nums), ans);
}