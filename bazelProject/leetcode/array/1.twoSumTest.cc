#include "gtest/gtest.h"
#include <vector>
#include "header.h"


TEST(message_test,content)
{
	std::vector<int> vec = {2,7,4,6,9,3};
    EXPECT_EQ(twosum(vec,9), std::make_pair(0,1));
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}