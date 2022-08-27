#include "347.TopKFrequentElements.h"
#include "gtest/gtest.h"

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

TEST(case_1,content)
{
    std::vector<int> vecNums = {1,1,1,2,2,3};
    std::vector<int> vecRes = {1,2};
    EXPECT_EQ(topKFrequent(vecNums, 2), vecRes);   
}


TEST(case_2,content)
{
    std::vector<int> vecNums = {1,2};
    std::vector<int> vecRes = {1,2};
    EXPECT_EQ(topKFrequent(vecNums, 2), vecRes);   
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}