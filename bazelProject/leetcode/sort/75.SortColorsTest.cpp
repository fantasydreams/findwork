#include "75.SortColors.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> vec = {2,0,2,1,1,0};
    std::vector<int> res = {0,0,1,1,2,2};
    sortColors(vec);
    EXPECT_EQ(vec, res);
}

TEST(case_2,content)
{
    std::vector<int> vec = {2,0,1};
    std::vector<int> res = {0,1,2};
    sortColors(vec);
    EXPECT_EQ(vec, res);
}

TEST(case_3,content)
{
    std::vector<int> vec = {0,0};
    std::vector<int> res = {0,0};
    sortColors(vec);
    EXPECT_EQ(vec, res);
}

TEST(case_4,content)
{
    std::vector<int> vec = {1,1};
    std::vector<int> res = {1,1};
    sortColors(vec);
    EXPECT_EQ(vec, res);
}

TEST(case_5,content)
{
    std::vector<int> vec = {2,2};
    std::vector<int> res = {2,2};
    sortColors(vec);
    EXPECT_EQ(vec, res);
}