#include "953.VerifyinganAlienDictionary.h"
#include "gtest/gtest.h"
#include <vector>

TEST(case_1, content)
{
    std::vector<std::string> words = {"hello","leetcode"};
    std::string order = "hlabcdefgijkmnopqrstuvwxyz";

    bool ans = true;
    EXPECT_EQ(isAlienSorted(words, order), ans);
}

TEST(case_2, content)
{
    std::vector<std::string> words = {"word","world","row"};
    std::string order = "worldabcefghijkmnpqstuvxyz";

    bool ans = false;
    EXPECT_EQ(isAlienSorted(words, order), ans);
}

TEST(case_3, content)
{
    std::vector<std::string> words = {"apple","app"};
    std::string order = "abcdefghijklmnopqrstuvwxyz";

    bool ans = false;
    EXPECT_EQ(isAlienSorted(words, order), ans);
}