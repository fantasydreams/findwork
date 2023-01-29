#include "198.HouseRobber.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {1,2,3,1};
    int ans = 4;
    EXPECT_EQ(rob(nums), ans);
    EXPECT_EQ(rob1(nums), ans);
    EXPECT_EQ(rob2(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {2,7,9,3,1};
    int ans = 12;
    EXPECT_EQ(rob(nums), ans);
    EXPECT_EQ(rob1(nums), ans);
    EXPECT_EQ(rob2(nums), ans);
}