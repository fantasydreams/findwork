#include "80.RemoveDuplicatesfromSortedArrayII.h"
#include "gtest/gtest.h"
#include <memory>
#include <type_traits>
#include <vector>
#include <cstdlib>
#include <cmath>

TEST(case_1, content)
{
    std::vector<int> vec = {1,1,1,2,2,3};
    std::vector<int> ans = {1,1,2,2,3,3};
    int len = 5;
    EXPECT_EQ(removeDuplicates(vec), len);
    EXPECT_EQ(vec, ans);
}

TEST(case_2, content)
{
    std::vector<int> vec = {0,0,1,1,1,1,2,3,3};
    std::vector<int> ans = {0,0,1,1,2,3,3,3,3};
    int len = 7;
    EXPECT_EQ(removeDuplicates(vec), len);
    EXPECT_EQ(vec, ans);
}