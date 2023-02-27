#include "384.ShuffleanArray.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    int n = 2, ans = 0;
    vector<int> nums = {1,2,3};
    Solution solu(nums);
    EXPECT_EQ(solu.reset(), nums);
}