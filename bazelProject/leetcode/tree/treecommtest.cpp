#include "gtest/gtest.h"
#include "treecomm.h"

TEST(case_1,content)
{
    std::vector<int> pre = {10, 5, 3, 7, 15, 18};
    std::vector<int> mid = {3, 5, 7, 10, 15, 18};
    TreeNode * root = CreateTree(pre, mid);
    std::string pres, mids ,posts;
    TraverseTreePost(root, posts);
    TraverseTreePre(root, pres);
    TraverseTreeMid(root, mids);
    // TraverseTreeLevelDebug(root);
    EXPECT_EQ(pres, "10 5 3 7 15 18");
    EXPECT_EQ(mids, "3 5 7 10 15 18");
    EXPECT_EQ(posts, "3 7 5 18 15 10");
    FreeTree(root);
}


TEST(case_2,content)
{
    std::vector<int> pre = {10, 5, 3, 1, 7, 6, 15, 13, 18};
    std::vector<int> mid = {1, 3, 5, 6, 7, 10, 13, 15, 18};
    TreeNode * root = CreateTree(pre, mid);
    std::string pres, mids ,posts;
    TraverseTreePost(root, posts);
    TraverseTreePre(root, pres);
    TraverseTreeMid(root, mids);
    // TraverseTreeLevelDebug(root);
    EXPECT_EQ(pres, "10 5 3 1 7 6 15 13 18");
    EXPECT_EQ(mids, "1 3 5 6 7 10 13 15 18");
    EXPECT_EQ(posts, "1 3 6 7 5 13 18 15 10");
    FreeTree(root);
}


int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}