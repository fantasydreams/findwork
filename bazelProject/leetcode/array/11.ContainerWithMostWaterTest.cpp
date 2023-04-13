#include "11.ContainerWithMostWater.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    int res = 49;
    EXPECT_EQ(maxArea(height), res);
    EXPECT_EQ(maxArea1(height), res);
}

TEST(case_2,content)
{
    std::vector<int> height = {1,1};
    int res = 1;
    EXPECT_EQ(maxArea(height), res);
    EXPECT_EQ(maxArea1(height), res);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}