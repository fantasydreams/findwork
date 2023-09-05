#include "78.Subsets.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> vec = {1,2,3};
    std::vector<std::vector<int>> ans = {
        {},
        {3},
        {2},
        {2,3},
        {1},
        {1,3},
        {1,2},
        {1,2,3}
    };
    EXPECT_EQ(subsets(vec), ans);
}

TEST(case_2, content)
{
    std::vector<int> vec = {0};
    std::vector<std::vector<int>> ans = {
        {},
        {0},
    };
    EXPECT_EQ(subsets(vec), ans);
}