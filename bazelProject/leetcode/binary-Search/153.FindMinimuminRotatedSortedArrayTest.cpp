#include "153.FindMinimuminRotatedSortedArray.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1, content) {
    std::vector<int> vec = {3,4,5,1,2};
    EXPECT_EQ(findMin(vec), *min_element(vec.begin(), vec.end()));
    EXPECT_EQ(findMin1(vec), *min_element(vec.begin(), vec.end()));
}


TEST(case_2, content) {
    std::vector<int> vec = {1};
    EXPECT_EQ(findMin(vec), *min_element(vec.begin(), vec.end()));
    EXPECT_EQ(findMin1(vec), *min_element(vec.begin(), vec.end()));
}


TEST(case_3, content) {
    std::vector<int> vec = {1,2};
    EXPECT_EQ(findMin(vec), *min_element(vec.begin(), vec.end()));
    EXPECT_EQ(findMin1(vec), *min_element(vec.begin(), vec.end()));
}


TEST(case_4, content) {
    std::vector<int> vec = {2,1};
    EXPECT_EQ(findMin(vec), *min_element(vec.begin(), vec.end()));
    EXPECT_EQ(findMin1(vec), *min_element(vec.begin(), vec.end()));
}

TEST(case_5, content) {
    std::vector<int> vec = {4,5,6,7,0,1,2};
    EXPECT_EQ(findMin(vec), *min_element(vec.begin(), vec.end()));
    EXPECT_EQ(findMin1(vec), *min_element(vec.begin(), vec.end()));
}

TEST(case_6, content) {
    std::vector<int> vec = {11,13,15,17};
    EXPECT_EQ(findMin(vec), *min_element(vec.begin(), vec.end()));
    EXPECT_EQ(findMin1(vec), *min_element(vec.begin(), vec.end()));
}