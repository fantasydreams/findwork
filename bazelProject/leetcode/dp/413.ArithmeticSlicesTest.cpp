#include "413.ArithmeticSlices.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {1};
    int ans = 0;
    EXPECT_EQ(numberOfArithmeticSlices(nums), ans);
    EXPECT_EQ(numberOfArithmeticSlices1(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {1, 2};
    int ans = 0;
    EXPECT_EQ(numberOfArithmeticSlices(nums), ans);
    EXPECT_EQ(numberOfArithmeticSlices1(nums), ans);
}

TEST(case_3,content)
{
    std::vector<int> nums = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(numberOfArithmeticSlices(nums), ans);
    EXPECT_EQ(numberOfArithmeticSlices1(nums), ans);
}

TEST(case_4,content)
{
    std::vector<int> nums = {1, 2, 3, 4};
    int ans = 3;
    EXPECT_EQ(numberOfArithmeticSlices(nums), ans);
    EXPECT_EQ(numberOfArithmeticSlices1(nums), ans);
}

TEST(case_5,content)
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int ans = 6;
    EXPECT_EQ(numberOfArithmeticSlices(nums), ans);
    EXPECT_EQ(numberOfArithmeticSlices1(nums), ans);
}

TEST(case_6,content)
{
    std::vector<int> nums = {1, 2, 3, 0, 1, 2};
    int ans = 2;
    EXPECT_EQ(numberOfArithmeticSlices(nums), ans);
    EXPECT_EQ(numberOfArithmeticSlices1(nums), ans);
}