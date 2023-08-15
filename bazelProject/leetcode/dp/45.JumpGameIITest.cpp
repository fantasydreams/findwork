#include "45.JumpGameII.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    int ans = 2;
    std::vector<int> step = {2,3,1,1,4};
    EXPECT_EQ(jump(step), ans);
}



TEST(case_2,content)
{
    int ans = 2;
    std::vector<int> step = {2,3,0,1,4};
    EXPECT_EQ(jump(step), ans);
    EXPECT_EQ(jump1(step), ans);
}

TEST(case_3,content)
{
    int ans = 0;
    std::vector<int> step = {2};
    EXPECT_EQ(jump(step), ans);
    EXPECT_EQ(jump1(step), ans);
}


TEST(case_4, content)
{
    int ans = 1;
    std::vector<int> step = {2,1};
    EXPECT_EQ(jump(step), ans);
    EXPECT_EQ(jump1(step), ans);
}


TEST(case_5, content)
{
    int ans = 2;
    std::vector<int> step = {2,1,5,1};
    EXPECT_EQ(jump(step), ans);
    EXPECT_EQ(jump1(step), ans);
}