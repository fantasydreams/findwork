#include "318.MaximumProductofWordLengths.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(case_1,content)
{
    std::vector<string> nums = {"abcw","baz","foo","bar","xtfn","abcdef"};
    int ans = 16;
    EXPECT_EQ(maxProduct(nums), ans);
}

TEST(case_2,content)
{
    std::vector<string> nums = {"a","ab","abc","d","cd","bcd","abcd"};
    int ans = 4;
    EXPECT_EQ(maxProduct(nums), ans);
}

TEST(case_3,content)
{
    std::vector<string> nums = {"a","aa","aaa","aaaa"};
    int ans = 0;
    EXPECT_EQ(maxProduct(nums), ans);
}
