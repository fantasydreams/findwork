#include "210.CourseScheduleII.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    int numCourses = 2, std::vector<std::vector<int> > prerequisites = {};
    std::vector<int> res= findOrder(2, prerequisites);
    EXPECT_EQ(prerequisites, res);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}