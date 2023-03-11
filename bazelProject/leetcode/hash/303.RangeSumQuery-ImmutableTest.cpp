#include "303.RangeSumQuery-Immutable.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj(nums);

    EXPECT_EQ(obj.sumRange(0,2),1);
    EXPECT_EQ(obj.sumRange(2,5),-1);
    EXPECT_EQ(obj.sumRange(0,5),-3);
}

TEST(case_2,content)
{
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray1 obj(nums);

    EXPECT_EQ(obj.sumRange(0,2),1);
    EXPECT_EQ(obj.sumRange(2,5),-1);
    EXPECT_EQ(obj.sumRange(0,5),-3);
}