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


TEST(case_5,content)
{
    std::vector<std::vector<char>> metrix = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    std::vector<std::vector<char>> ans = {{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};
    solveBFS(metrix);
    EXPECT_EQ(metrix, ans);
}

TEST(case_6,content)
{
    std::vector<std::vector<char>> metrix = {{'X'}};
    std::vector<std::vector<char>> ans = {{'X'}};
    solveBFS(metrix);
    EXPECT_EQ(metrix, ans);
}

TEST(case_7,content)
{
    std::vector<std::vector<char>> metrix = {{'X', 'O', 'X'}, 
                                             {'O', 'X', 'O'},
                                             {'X', 'O', 'X'}};
    std::vector<std::vector<char>> ans = metrix;
    solveBFS(metrix);
    EXPECT_EQ(metrix, ans);
}


TEST(case_8,content)
{
    std::vector<std::vector<char>> metrix = {{'X','O','X','O','X','O'},
                                             {'O','X','O','X','O','X'},
                                             {'X','O','X','O','X','O'},
                                             {'O','X','O','X','O','X'}};

    std::vector<std::vector<char>> ans = {{'X','O','X','O','X','O'},
                                          {'O','X','X','X','X','X'},
                                          {'X','X','X','X','X','O'},
                                          {'O','X','O','X','O','X'}};
    solveBFS(metrix);
    EXPECT_EQ(metrix, ans);
}

TEST(case_5,content1)
{
    std::vector<std::vector<char>> metrix = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    std::vector<std::vector<char>> ans = {{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};
    solveBFS1(metrix);
    EXPECT_EQ(metrix, ans);
}

TEST(case_6,content1)
{
    std::vector<std::vector<char>> metrix = {{'X'}};
    std::vector<std::vector<char>> ans = {{'X'}};
    solveBFS1(metrix);
    EXPECT_EQ(metrix, ans);
}

TEST(case_7,content1)
{
    std::vector<std::vector<char>> metrix = {{'X', 'O', 'X'}, 
                                             {'O', 'X', 'O'},
                                             {'X', 'O', 'X'}};
    std::vector<std::vector<char>> ans = metrix;
    solveBFS1(metrix);
    EXPECT_EQ(metrix, ans);
}


TEST(case_8,content1)
{
    std::vector<std::vector<char>> metrix = {{'X','O','X','O','X','O'},
                                             {'O','X','O','X','O','X'},
                                             {'X','O','X','O','X','O'},
                                             {'O','X','O','X','O','X'}};

    std::vector<std::vector<char>> ans = {{'X','O','X','O','X','O'},
                                          {'O','X','X','X','X','X'},
                                          {'X','X','X','X','X','O'},
                                          {'O','X','O','X','O','X'}};
    solveBFS1(metrix);
    EXPECT_EQ(metrix, ans);
}


TEST(case_9,content1)
{
    std::vector<std::vector<char>> metrix = {{'X','X','X','X'},
                                            {'X','O','O','X'},
                                            {'X','X','O','X'},
                                            {'X','O','X','X'}};

    std::vector<std::vector<char>> ans = {{'X','X','X','X'},
                                          {'X','X','X','X'},
                                          {'X','X','X','X'},
                                          {'X','O','X','X'}};
    solveBFS1(metrix);
    EXPECT_EQ(metrix, ans);
}