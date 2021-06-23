#include "gtest/gtest.h"
#include <vector>
#include "header.h"


TEST(case_1,content)
{
	std::vector<int> vec = {2,7,4,6,9,3};
    std::vector<int> res = {0,1};
    EXPECT_EQ(twoSum(vec,9), res);
}

TEST(case_2,content)
{
	std::vector<int> vec = {3,2,4};
    std::vector<int> res = {1,2};
    EXPECT_EQ(twoSum(vec,6), res);
}

TEST(case_3,content)
{
	std::vector<int> vec = {3,3};
    std::vector<int> res = {0,1};
    EXPECT_EQ(twoSum(vec,6), res);
}

TEST(case_4,content)
{
	std::vector<int> vec = {3,3,3};
    std::vector<int> res = {0,1};
    EXPECT_EQ(twoSum(vec,6), res);
}

TEST(case_5,content)
{
	std::vector<int> vec = {3,3,3};
    std::vector<int> res = {0,1};
    EXPECT_EQ(twoSum(vec,6), res);
}

TEST(case_6,content)
{
	std::vector<int> vec = {3,3,3};
    std::vector<int> res = {};
    EXPECT_EQ(twoSum(vec,7), res);
}

TEST(case_7,content)
{
	std::vector<int> vec = {3};
    std::vector<int> res = {};
    EXPECT_EQ(twoSum(vec,4), res);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}