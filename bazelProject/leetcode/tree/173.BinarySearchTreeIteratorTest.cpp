#include "173.BinarySearchTreeIterator.h"
#include "treecomm.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> pre = {7, 3, 15, 9, 20};
    std::vector<int> mid = {3, 7, 9, 15, 20};
    TreeNode * root = CreateTreePreMid(pre, mid);
    
    BSTIterator tIt(root);
    EXPECT_EQ(tIt.hasNext(), true);
    EXPECT_EQ(tIt.next(), 3);

    EXPECT_EQ(tIt.hasNext(), true);
    EXPECT_EQ(tIt.next(), 7);

    EXPECT_EQ(tIt.hasNext(), true);
    EXPECT_EQ(tIt.next(), 9);

    EXPECT_EQ(tIt.hasNext(), true);
    EXPECT_EQ(tIt.next(), 15);

    EXPECT_EQ(tIt.hasNext(), true);
    EXPECT_EQ(tIt.next(), 20);

    EXPECT_EQ(tIt.hasNext(), false); 

    FreeTree(root);
}