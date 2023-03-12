#include "287.FindtheDuplicateNumber.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    vector<int> nums = {1,3,4,2,2};
    int ans = 2;
    EXPECT_EQ(findDuplicate(nums), ans);
    EXPECT_EQ(findDuplicate3(nums), ans);
    EXPECT_EQ(findDuplicate1(nums), ans);
    EXPECT_EQ(findDuplicate2(nums), ans);
}

TEST(case_2,content)
{
    vector<int> nums = {3,1,3,4,2};
    int ans = 3;
    EXPECT_EQ(findDuplicate(nums), ans);
    EXPECT_EQ(findDuplicate3(nums), ans);
    EXPECT_EQ(findDuplicate1(nums), ans);
    EXPECT_EQ(findDuplicate2(nums), ans);
}

TEST(case_3,content)
{
    vector<int> nums = {7,9,7,4,2,8,7,7,1,5};
    int ans = 7;
    EXPECT_EQ(findDuplicate(nums), ans);
    EXPECT_EQ(findDuplicate3(nums), ans);
    EXPECT_EQ(findDuplicate1(nums), ans);
    EXPECT_EQ(findDuplicate2(nums), ans);
}