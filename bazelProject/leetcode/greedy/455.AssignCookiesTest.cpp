#include "455.AssignCookies.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
	std::vector<int> g = {1,2,3};
    std::vector<int> c = {1,2};
    EXPECT_EQ(findContentChildren(g,c), 2);
}

TEST(case_2,content)
{
	std::vector<int> g = {1,2,3};
    std::vector<int> c = {};
    EXPECT_EQ(findContentChildren(g,c), 0);
}


TEST(case_3,content)
{
	std::vector<int> g = {};
    std::vector<int> c = {1,2};
    EXPECT_EQ(findContentChildren(g,c), 0);
}

TEST(case_4,content)
{
	std::vector<int> g = {1,3};
    std::vector<int> c = {1,1};
    EXPECT_EQ(findContentChildren(g,c), 1);
}