#include "130.SurroundedRegions.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<std::vector<char>> metrix = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    std::vector<std::vector<char>> ans = {{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};
    solve(metrix);
    EXPECT_EQ(metrix, ans);
}

TEST(case_2,content)
{
    std::vector<std::vector<char>> metrix = {{'X'}};
    std::vector<std::vector<char>> ans = {{'X'}};
    solve(metrix);
    EXPECT_EQ(metrix, ans);
}

TEST(case_3,content)
{
    std::vector<std::vector<char>> metrix = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    std::vector<std::vector<char>> ans = {{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};
    solve1(metrix);
    EXPECT_EQ(metrix, ans);
}

TEST(case_4,content)
{
    std::vector<std::vector<char>> metrix = {{'X'}};
    std::vector<std::vector<char>> ans = {{'X'}};
    solve1(metrix);
    EXPECT_EQ(metrix, ans);
}