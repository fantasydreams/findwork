#include "1200.MinimumAbsoluteDifference.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> arr = {4,2,1,3};
    std::vector<std::vector<int> > res = {{1,2}, {2,3}, {3,4}};
    EXPECT_EQ(minimumAbsDifference(arr), res);
    EXPECT_EQ(minimumAbsDifference1(arr), res);
    EXPECT_EQ(minimumAbsDifference2(arr), res);
}

TEST(case_2,content)
{
    std::vector<int> arr = {1,3,6,10,15};
    std::vector<std::vector<int> > res = {{1,3}};
    EXPECT_EQ(minimumAbsDifference(arr), res);
    EXPECT_EQ(minimumAbsDifference1(arr), res);
    EXPECT_EQ(minimumAbsDifference2(arr), res);
}

TEST(case_3,content)
{
    std::vector<int> arr = {3,8,-10,23,19,-4,-14,27};
    std::vector<std::vector<int> > res = {{-14,-10}, {19,23}, {23,27}};
    EXPECT_EQ(minimumAbsDifference(arr), res);
    EXPECT_EQ(minimumAbsDifference1(arr), res);
    EXPECT_EQ(minimumAbsDifference2(arr), res);
}

TEST(case_4,content)
{
    std::vector<int> arr = {3,2,11,1,-1,0,5};
    std::vector<std::vector<int> > res = {{-1, 0}, {0 ,1},{1,2}, {2,3}};
    EXPECT_EQ(minimumAbsDifference(arr), res);
    EXPECT_EQ(minimumAbsDifference1(arr), res);
    EXPECT_EQ(minimumAbsDifference2(arr), res);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}