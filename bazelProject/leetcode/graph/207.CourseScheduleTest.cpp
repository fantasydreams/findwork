#include "207.CourseSchedule.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    int numCourses = 2;
    std::vector<std::vector<int> > prerequisites = {{1,0}};
    int ans = true;
    EXPECT_EQ(canFinish(numCourses, prerequisites), ans);
    EXPECT_EQ(canFinish1(numCourses, prerequisites), ans);
}


TEST(case_2, content) {
    int numCourses = 2;
    std::vector<std::vector<int> > prerequisites = {{1,0}, {0, 1}};
    int ans = false;
    EXPECT_EQ(canFinish(numCourses, prerequisites), ans);
    EXPECT_EQ(canFinish1(numCourses, prerequisites), ans);
}