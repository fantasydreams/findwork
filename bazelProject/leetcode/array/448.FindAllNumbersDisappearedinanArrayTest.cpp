
#include "448.FindAllNumbersDisappearedinanArray.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> nums = {1, 1};
    std::vector<int> ans = {2};
    EXPECT_EQ(findDisappearedNumbers(nums), ans);
}

TEST(case_2,content)
{
    std::vector<int> nums = {4,3,2,7,8,2,3,1};
    std::vector<int> ans = {5,6};
    EXPECT_EQ(findDisappearedNumbers(nums), ans);
}

TEST(case_3,content)
{
    std::vector<int> nums = {1,2,2,4};
    std::vector<int> ans = {3};
    EXPECT_EQ(findDisappearedNumbers(nums), ans);
}