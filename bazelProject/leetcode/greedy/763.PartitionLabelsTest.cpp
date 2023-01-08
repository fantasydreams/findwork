#include "763.PartitionLabels.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::string s = "ababcbacadefegdehijhklij";
	std::vector<int> f = {9,7,8};
    EXPECT_EQ(partitionLabels(s), f);
}


TEST(case_2,content)
{
    std::string s = "eccbbbbdec";
	std::vector<int> f = {10};
    EXPECT_EQ(partitionLabels(s), f);
}

TEST(case_3,content)
{
    std::string s = "caedbdedda";
	std::vector<int> f = {1,9};
    EXPECT_EQ(partitionLabels(s), f);
}
