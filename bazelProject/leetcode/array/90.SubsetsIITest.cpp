#include "90.SubsetsII.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> vec = {1,2,3};
    std::vector<std::vector<int>> ans = {
        {},
        {3},
        {2},
        {2,3},
        {1},
        {1,3},
        {1,2},
        {1,2,3}
    };
    std::sort(ans.begin(), ans.end());
    EXPECT_EQ(subsetsWithDup(vec), ans);

    vec = {1,2,3};
    vector<vector<int> > tmp = subsetsWithDup1(vec);
    std::sort(tmp.begin(), tmp.end());
    EXPECT_EQ(tmp, ans);
}

TEST(case_2, content)
{
    std::vector<int> vec = {0};
    std::vector<std::vector<int>> ans = {
        {},
        {0},
    };
    EXPECT_EQ(subsetsWithDup(vec), ans);

    vec = {0};
    vector<vector<int> > tmp = subsetsWithDup1(vec);
    std::sort(tmp.begin(), tmp.end());
    EXPECT_EQ(tmp, ans);
}


TEST(case_3, content)
{
    std::vector<int> vec = {1,2,2};
    std::vector<std::vector<int>> ans = {
        {},
        {1},
        {1,2},
        {1,2,2},
        {2},
        {2,2}
    };

    EXPECT_EQ(subsetsWithDup(vec), ans);

    vec = {1,2,2};
    vector<vector<int> > tmp = subsetsWithDup1(vec);
    std::sort(tmp.begin(), tmp.end());
    EXPECT_EQ(tmp, ans);
}