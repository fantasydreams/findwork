#include "870.AdvantageShuffle.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<int> nums1 = {2,7,11,15}, nums2 = {1,10,4,11};
    vector<int> ans = {2,11,7,15};
    EXPECT_EQ(advantageCount2(nums1,nums2), ans);
    EXPECT_EQ(advantageCount1(nums1,nums2), ans);
    EXPECT_EQ(advantageCount(nums1,nums2), ans);
}

TEST(case_2,content)
{
	std::vector<int> nums1 = {12,24,8,32}, nums2 = {13,25,32,11};
    vector<int> ans = {24,32,8,12};
    EXPECT_EQ(advantageCount2(nums1,nums2), ans);
    EXPECT_EQ(advantageCount1(nums1,nums2), ans);
    EXPECT_EQ(advantageCount(nums1,nums2), ans);
}