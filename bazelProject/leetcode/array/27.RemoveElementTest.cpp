#include "27.RemoveElement.h"
#include "gtest/gtest.h"

bool checkinSame(const std::vector<int>& a, const std::vector<int>& b) {
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

TEST(case_1,content)
{
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::vector<int> ans = {8,6,2,5,4,8,3,7};
    EXPECT_EQ(removeElement(height, 1), ans.size());
    EXPECT_EQ(checkinSame(ans, height), true);
}

TEST(case_2,content)
{
    std::vector<int> height = {1,1};
    std::vector<int> ans = {};
    EXPECT_EQ(removeElement(height, 1), 0);
    EXPECT_EQ(checkinSame(ans, height), true);
}


TEST(case_3,content)
{
    std::vector<int> height = {1,1,2,3,4,4,1,5, 3, 4};
    std::vector<int> ans = {1,1,2,3,1,5,3};
    EXPECT_EQ(removeElement(height, 4), ans.size());
    EXPECT_EQ(checkinSame(ans, height), true);
}



TEST(case_4,content)
{
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::vector<int> ans = {8,6,2,5,4,8,3,7};
    EXPECT_EQ(removeElement1(height, 1), ans.size());
    EXPECT_EQ(checkinSame(ans, height), true);
}

TEST(case_5,content)
{
    std::vector<int> height = {1,1};
    std::vector<int> ans = {};
    EXPECT_EQ(removeElement1(height, 1), 0);
    EXPECT_EQ(checkinSame(ans, height), true);
}


TEST(case_6,content)
{
    std::vector<int> height = {1,1,2,3,4,4,1,5, 3, 4};
    std::vector<int> ans = {1,1,2,3,1,5,3};
    EXPECT_EQ(removeElement1(height, 4), ans.size());
    EXPECT_EQ(checkinSame(ans, height), true);
}