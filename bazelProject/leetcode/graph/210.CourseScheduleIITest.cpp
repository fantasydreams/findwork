#include "210.CourseScheduleII.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    int numCourses = 2;
    std::vector<std::vector<int> > prerequisites = {{0, 1}};
    std::vector<int> res = findOrder(2, prerequisites);
    std::vector<int> bfs = findOrderBfs(numCourses, prerequisites);
    std::vector<int> ans = {1, 0};
    EXPECT_EQ(ans, res);
    EXPECT_EQ(ans, bfs);
    EXPECT_EQ(findOrderBfs1(numCourses, prerequisites), ans);
}


TEST(case_2,content)
{
    int numCourses = 4;
    std::vector<std::vector<int> > prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    std::vector<int> res = findOrder(numCourses, prerequisites);
    std::vector<int> bfs = findOrderBfs(numCourses, prerequisites);
    std::vector<int> ans = {0, 1, 2, 3};
    EXPECT_EQ(ans, res);
    EXPECT_EQ(ans, bfs);
    // EXPECT_EQ(findOrderBfs1(numCourses, prerequisites), ans);
}


TEST(case_3,content)
{
    int numCourses = 1;
    std::vector<std::vector<int> > prerequisites = {};
    std::vector<int> res = findOrder(numCourses, prerequisites);
    std::vector<int> bfs = findOrderBfs(numCourses, prerequisites);
    std::vector<int> ans = {0};
    EXPECT_EQ(ans, res);
    EXPECT_EQ(ans, bfs);
    EXPECT_EQ(findOrderBfs1(numCourses, prerequisites), ans);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}