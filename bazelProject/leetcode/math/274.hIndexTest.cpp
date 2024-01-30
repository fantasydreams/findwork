#include "274.hIndex.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int ans = 3;
    std::vector<int> step = {3,0,6,1,5};
    EXPECT_EQ(hIndexBucketSort(step), ans); 
    EXPECT_EQ(hIndex(step), ans);
}


TEST(case_2,content)
{
    int ans = 1;
    std::vector<int> step = {1,3,1};
    EXPECT_EQ(hIndexBucketSort(step), ans); 
    EXPECT_EQ(hIndex(step), ans);
}