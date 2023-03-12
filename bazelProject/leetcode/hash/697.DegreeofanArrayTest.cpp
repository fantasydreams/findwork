#include "697.DegreeofanArray.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> nums = {1,2,2,3,1};
    int ans = 2;
    
    EXPECT_EQ(findShortestSubArray(nums), ans);
    EXPECT_EQ(findShortestSubArray1(nums), ans);   
}


TEST(case_2,content)
{
    std::vector<int> nums = {1,2,2,3,1,4,2};
    int ans = 6;
    
    EXPECT_EQ(findShortestSubArray(nums), ans);   
    EXPECT_EQ(findShortestSubArray1(nums), ans);   
}