#include "116.PopulatingNextRightPointersinEachNode.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    std::vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> mid = {4, 2, 5, 1, 6, 3, 7};
    TreeNode * root = CreateTreePreMid(pre, mid);
    TreeNode * newTree = connect(root);
    std::string preS, midS;
    TraverseTreePreNoRecursion(newTree, preS);
    TraverseTreeMidNoRecursion(newTree, midS);
    std::string ansPre = "1 2 4 5 3 6 7";
    std::string ansMid = "4 2 5 1 6 3 7";
    EXPECT_EQ(preS, ansPre);
    EXPECT_EQ(midS, ansMid);
    FreeTree(newTree);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}