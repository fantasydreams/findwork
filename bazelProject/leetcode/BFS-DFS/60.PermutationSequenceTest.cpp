#include "60.PermutationSequence.h"
#include "gtest/gtest.h"
#include <string>
#include <type_traits>

TEST(case_1, content)
{
    std::string ans = "1";   
    int n = 1, k = 1;
    EXPECT_EQ(getPermutation(n, k), ans);
    EXPECT_EQ(getPermutation1(n, k), ans);
}


TEST(case_2, content)
{
    std::string ans = "21";   
    int n = 2, k = 2;
    EXPECT_EQ(getPermutation(n, k), ans);
    EXPECT_EQ(getPermutation1(n, k), ans);
}

TEST(case_3, content)
{
    std::string ans = "213";
    int n = 3, k = 3;
    EXPECT_EQ(getPermutation(n, k), ans);
    EXPECT_EQ(getPermutation1(n, k), ans);
}

TEST(case_4, content)
{
    std::string ans = "2314";   
    int n = 4, k = 9;
    EXPECT_EQ(getPermutation(n, k), ans);
    EXPECT_EQ(getPermutation1(n, k), ans);
}

TEST(case_5, content)
{
    std::string ans = "123";   
    int n = 3, k = 1;
    EXPECT_EQ(getPermutation(n, k), ans);
    EXPECT_EQ(getPermutation1(n, k), ans);
}