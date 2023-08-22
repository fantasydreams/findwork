#include "55.JumpGame.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    bool ans = true;
	std::vector<int> nums = {2,3,1,1,4};
    EXPECT_EQ(canJump(nums), ans);
}

TEST(case_2,content)
{
    bool ans = false;
	std::vector<int> nums = {3,2,1,0,4};
    EXPECT_EQ(canJump(nums), ans);
}


TEST(case_3, content)
{
    bool ans = true;
	std::vector<int> nums = {};
    EXPECT_EQ(canJump(nums), ans);
    EXPECT_EQ(canJumpDp(nums), ans);
}


TEST(case_4, content)
{
    bool ans = true;
	std::vector<int> nums = {1};
    EXPECT_EQ(canJump(nums), ans);
    EXPECT_EQ(canJumpDp(nums), ans);
}


TEST(case_5, content)
{
    bool ans = true;
	std::vector<int> nums = {0};
    EXPECT_EQ(canJump(nums), ans);
    EXPECT_EQ(canJumpDp(nums), ans);
}