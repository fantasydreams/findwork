#include "785.IsGraphBipartite.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<std::vector<int> > graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    bool ans = false;

    EXPECT_EQ(isBipartite(graph), ans);
}


TEST(case_2,content)
{
    std::vector<std::vector<int> > graph = {{1,3},{0,2},{1,3},{0,2}};
    bool ans = true;
    EXPECT_EQ(isBipartite(graph), ans);
}