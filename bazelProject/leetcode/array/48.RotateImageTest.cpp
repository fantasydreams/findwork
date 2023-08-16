#include "48.RotateImage.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<std::vector<int>> image = {
        {1,2},
        {3,4}
    };
    std::vector<std::vector<int>> ans = {
        {3,1},
        {4,2}
    };

    std::vector<std::vector<int>> tmp = image;
    rotate(tmp);
    EXPECT_EQ(tmp, ans);
    tmp = image;
    rotate1(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate2(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate3(tmp);
    EXPECT_EQ(tmp, ans);
}

TEST(case_2,content)
{
    std::vector<std::vector<int>> image = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    std::vector<std::vector<int>> ans = {
        {7,4,1},
        {8,5,2},
        {9,6,3}
    };
    std::vector<std::vector<int>> tmp = image;
    rotate(tmp);
    EXPECT_EQ(tmp, ans);
    tmp = image;
    rotate1(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate2(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate3(tmp);
    EXPECT_EQ(tmp, ans);
}

TEST(case_3,content)
{
    std::vector<std::vector<int>> image = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    std::vector<std::vector<int>> ans = {
        {15,13,2,5},
        {14,3,4,1},
        {12,6,8,9},
        {16,7,10,11}
    };
    std::vector<std::vector<int>> tmp = image;
    rotate(tmp);
    EXPECT_EQ(tmp, ans);
    tmp = image;
    rotate1(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate2(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate3(tmp);
    EXPECT_EQ(tmp, ans);
}

TEST(case_4,content)
{
    std::vector<std::vector<int>> image = {
        {1}
    };
    std::vector<std::vector<int>> ans = {
        {1}
    };
    std::vector<std::vector<int>> tmp = image;
    rotate(tmp);
    EXPECT_EQ(tmp, ans);
    tmp = image;
    rotate1(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate2(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate3(tmp);
    EXPECT_EQ(tmp, ans);
}

TEST(case_5,content)
{
    std::vector<std::vector<int>> image = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    std::vector<std::vector<int>> ans = {
        {21,16,11,6,1},
        {22,17,12,7,2},
        {23,18,13,8,3},
        {24,19,14,9,4},
        {25,20,15,10,5}
    };
    std::vector<std::vector<int>> tmp = image;
    rotate(tmp);
    EXPECT_EQ(tmp, ans);
    tmp = image;
    rotate1(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate2(tmp);
    EXPECT_EQ(tmp, ans);

    tmp = image;
    rotate3(tmp);
    EXPECT_EQ(tmp, ans);
}