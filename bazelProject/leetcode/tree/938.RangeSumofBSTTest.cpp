#include "gtest/gtest.h"
#include "938.RangeSumofBST.h"

TEST(case_1,content)
{
    TreeNode * root = nullptr;
    EXPECT_EQ(rangeSumBST(root, 5, 10), 0);
}


int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}