#include "373.FindKPairswithSmallestSums.h"
#include "gtest/gtest.h"

TEST(case1, content) {
   int k = 3;
   vector<int> nums1 = {1,7,11}, nums2 = {2,4,6};
   vector<vector<int>> ans = {{1,2},{1,4},{1,6}};
   EXPECT_EQ(kSmallestPairs(nums1, nums2, k), ans);
}


TEST(case2, content) {
   int k = 2;
   vector<int> nums1 = {1,1,2}, nums2 = {1,2,3};
   vector<vector<int>> ans = {{1,1},{1,1}};
   EXPECT_EQ(kSmallestPairs(nums1, nums2, k), ans);
}

TEST(case3, content) {
   int k = 3;
   vector<int> nums1 = {1,2,4,5,6}, nums2 = {3,5,7,9};
   vector<vector<int>> ans = {{1,3},{2,3}, {1,5}};
   EXPECT_EQ(kSmallestPairs(nums1, nums2, k), ans);
}