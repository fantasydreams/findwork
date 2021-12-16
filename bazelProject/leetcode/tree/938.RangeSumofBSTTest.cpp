#include "gtest/gtest.h"
#include "938.RangeSumofBST.h"

TEST(case_1,content)
{
    TreeNode * root = nullptr;
    EXPECT_EQ(rangeSumBST(root, 5, 10), 0);
}


TEST(case_2,content)
{
    std::vector<int> pre = {10, 5, 3, 1, 7, 6, 15, 13, 18};
    std::vector<int> mid = {1, 3, 5, 6, 7, 10, 13, 15, 18};
    TreeNode * root = CreateTree(pre, mid);
    EXPECT_EQ(rangeSumBST(root, 6, 10), 23);
    FreeTree(root);
}


TEST(case_3,content)
{
    std::vector<int> pre = {10, 5, 3, 7, 15, 18};
    std::vector<int> mid = {3, 5, 7, 10, 15, 18};
    TreeNode * root = CreateTree(pre, mid);
    EXPECT_EQ(rangeSumBST(root, 7, 15), 32);
    FreeTree(root);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}