#include "219.ContainsDuplicateII.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> nums = {1,2,3,1};
    int k = 3;
    bool ans = true;
    EXPECT_EQ(containsNearbyDuplicate(nums, k), ans);
}


TEST(case_2, content) {
    std::vector<int> nums = {1,0,1,1};
    int k = 1;
    bool ans = true;
    EXPECT_EQ(containsNearbyDuplicate(nums, k), ans);
}

TEST(case_3, content) {
    std::vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    bool ans = false;
    EXPECT_EQ(containsNearbyDuplicate(nums, k), ans);
}