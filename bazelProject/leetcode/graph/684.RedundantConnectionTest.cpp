#include "684.RedundantConnection.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> ans = {1,4};
    EXPECT_EQ(findRedundantConnection(edges), ans);
}

TEST(case_2,content)
{
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> ans = {2, 3};
    EXPECT_EQ(findRedundantConnection(edges), ans);
}