#include "31.NextPermutation.h"
#include "gtest/gtest.h"
#include <string>
#include <vector>

TEST(case_1,content)
{
	std::vector<int> vec = {1,2,3};
    nextPermutation(vec);
    std::vector<int> ans = {1,3,2};
    EXPECT_EQ(vec, ans);
}


TEST(case_2,content)
{
	std::vector<int> vec = {1,2,3};
    nextPermutationStl(vec);
    std::vector<int> ans = {1,3,2};
    EXPECT_EQ(vec, ans);
}

TEST(case_3,content)
{
	std::vector<int> vec = {1,2,3,2};
    nextPermutationStl(vec);
    std::vector<int> ans = {1,3,2,2};
    EXPECT_EQ(vec, ans);
}

TEST(case_4,content)
{
	std::vector<int> vec = {1,2,3};
    nextPermutation(vec);
    std::vector<int> ans = {1,3,2};
    EXPECT_EQ(vec, ans);
}

TEST(case_5,content)
{
	std::vector<int> vec = {1,2,3,2};
    nextPermutation(vec);
    std::vector<int> ans = {1,3,2,2};
    EXPECT_EQ(vec, ans);
}