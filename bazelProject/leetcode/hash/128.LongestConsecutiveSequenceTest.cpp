#include "128.LongestConsecutiveSequence.h"
#include "gtest/gtest.h"

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

TEST(case_1,content)
{
    std::vector<int> vecNums = {100,4,200,1,3,2};
    int ans = 4;
    EXPECT_EQ(longestConsecutive(vecNums), ans);   
    EXPECT_EQ(longestConsecutive1(vecNums), ans);   
    EXPECT_EQ(longestConsecutive2(vecNums), ans);  
}


TEST(case_2,content)
{
    std::vector<int> vecNums = {0,3,7,2,5,8,4,6,0,1};
    int ans = 9;
    EXPECT_EQ(longestConsecutive(vecNums), ans);   
    EXPECT_EQ(longestConsecutive1(vecNums), ans);   
    EXPECT_EQ(longestConsecutive2(vecNums), ans);
}

TEST(case_3,content)
{
    std::vector<int> vecNums = {};
    int ans = 0;
    EXPECT_EQ(longestConsecutive(vecNums), ans);   
    EXPECT_EQ(longestConsecutive1(vecNums), ans);   
    EXPECT_EQ(longestConsecutive2(vecNums), ans);
}

TEST(case_4,content)
{
    std::vector<int> vecNums = {0};
    int ans = 1;
    EXPECT_EQ(longestConsecutive(vecNums), ans);   
    EXPECT_EQ(longestConsecutive1(vecNums), ans);   
    EXPECT_EQ(longestConsecutive2(vecNums), ans);
}