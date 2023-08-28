#include "avltree.h"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>


TEST(case_1, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(1), true);
    EXPECT_EQ(oAvlTree.Insert(1), false);
}
