#include "220.ContainsDuplicateIII.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> nums = {1,2,3,1};
    int indexDiff = 3, valueDiff = 0;
    bool bAns = true;

    EXPECT_EQ(containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff), bAns);
    EXPECT_EQ(containsNearbyAlmostDuplicateBuckets(nums, indexDiff, valueDiff), bAns);
}


TEST(case_2, content) {
    std::vector<int> nums = {1,5,9,1,5,9};
    int indexDiff = 2, valueDiff = 3;
    bool bAns = false;

    EXPECT_EQ(containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff), bAns);
    EXPECT_EQ(containsNearbyAlmostDuplicateBuckets(nums, indexDiff, valueDiff), bAns);
}

TEST(case_3, content) {
    std::vector<int> nums = {1,0,1,1};
    int indexDiff = 1, valueDiff = 2;
    bool bAns = true;

    EXPECT_EQ(containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff), bAns);
    EXPECT_EQ(containsNearbyAlmostDuplicateBuckets(nums, indexDiff, valueDiff), bAns);
}


TEST(case_4, content) {
    std::vector<int> nums = {2,0,-2,2};
    int indexDiff =2, valueDiff = 1;
    bool bAns = false;

    EXPECT_EQ(containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff), bAns);
    EXPECT_EQ(containsNearbyAlmostDuplicateBuckets(nums, indexDiff, valueDiff), bAns);
}