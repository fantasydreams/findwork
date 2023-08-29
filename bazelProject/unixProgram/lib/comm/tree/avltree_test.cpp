#include "avltree.h"
#include "avltree_tools.h"
#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>


// 测试RR
TEST(case_1, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(1), true);
    EXPECT_EQ(oAvlTree.Insert(1), false);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);

    EXPECT_EQ(oAvlTree.Insert(2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    EXPECT_EQ(oAvlTree.Insert(3), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 2);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "2 1 3");
    EXPECT_EQ(sMid, "1 2 3");
    EXPECT_EQ(sPost, "1 3 2");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1 3");
    EXPECT_EQ(sMid, "1 3");
    EXPECT_EQ(sPost, "3 1");

    EXPECT_EQ(oAvlTree.Remove(3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1");
    EXPECT_EQ(sMid, "1");
    EXPECT_EQ(sPost, "1");

    EXPECT_EQ(oAvlTree.Remove(1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 0);
    EXPECT_EQ(oAvlTree.GetTree(), nullptr);

    EXPECT_EQ(oAvlTree.Remove(1), false);
}
    
// RR 存在叶子结点
TEST(case_2, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(1), true);
    EXPECT_EQ(oAvlTree.Insert(1), false);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);

    EXPECT_EQ(oAvlTree.Insert(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    EXPECT_EQ(oAvlTree.Insert(3), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    EXPECT_EQ(oAvlTree.Insert(2), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    EXPECT_EQ(oAvlTree.Insert(4), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1 -1 3 2 4");
    EXPECT_EQ(sMid, "-1 1 2 3 4");
    EXPECT_EQ(sPost, "-1 2 4 3 1");

    EXPECT_EQ(oAvlTree.Insert(5), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "3 1 -1 2 4 5");
    EXPECT_EQ(sMid, "-1 1 2 3 4 5");
    EXPECT_EQ(sPost, "-1 2 1 5 4 3");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(4), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "3 1 -1 2 5");
    EXPECT_EQ(sMid, "-1 1 2 3 5");
    EXPECT_EQ(sPost, "-1 2 1 5 3");

    EXPECT_EQ(oAvlTree.Remove(5), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1 -1 3 2");
    EXPECT_EQ(sMid, "-1 1 2 3");
    EXPECT_EQ(sPost, "-1 2 3 1");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "2 1 3");
    EXPECT_EQ(sMid, "1 2 3");
    EXPECT_EQ(sPost, "1 3 2");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1 3");
    EXPECT_EQ(sMid, "1 3");
    EXPECT_EQ(sPost, "3 1");

    EXPECT_EQ(oAvlTree.Remove(3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1");
    EXPECT_EQ(sMid, "1");
    EXPECT_EQ(sPost, "1");

    EXPECT_EQ(oAvlTree.Remove(1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 0);
    EXPECT_EQ(oAvlTree.GetTree(), nullptr);

    EXPECT_EQ(oAvlTree.Remove(1), false);
}

// RL 无叶子结点
TEST(case_3, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(1), true);
    EXPECT_EQ(oAvlTree.Insert(3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);

    EXPECT_EQ(oAvlTree.Insert(2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "2 1 3");
    EXPECT_EQ(sMid, "1 2 3");
    EXPECT_EQ(sPost, "1 3 2");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1 3");
    EXPECT_EQ(sMid, "1 3");
    EXPECT_EQ(sPost, "3 1");

    EXPECT_EQ(oAvlTree.Remove(3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1");
    EXPECT_EQ(sMid, "1");
    EXPECT_EQ(sPost, "1");

    EXPECT_EQ(oAvlTree.Remove(1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 0);
    EXPECT_EQ(oAvlTree.GetTree(), nullptr);

    EXPECT_EQ(oAvlTree.Remove(1), false);
}

//RL 有叶子结点
TEST(case_4, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(1), true);
    EXPECT_EQ(oAvlTree.Insert(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);

    EXPECT_EQ(oAvlTree.Insert(6), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    EXPECT_EQ(oAvlTree.Insert(4), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    EXPECT_EQ(oAvlTree.Insert(7), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1 -1 6 4 7");
    EXPECT_EQ(sMid, "-1 1 4 6 7");
    EXPECT_EQ(sPost, "-1 4 7 6 1");

    EXPECT_EQ(oAvlTree.Insert(5), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "4 1 -1 6 5 7");
    EXPECT_EQ(sMid, "-1 1 4 5 6 7");
    EXPECT_EQ(sPost, "-1 1 5 7 6 4");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(7), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "4 1 -1 6 5");
    EXPECT_EQ(sMid, "-1 1 4 5 6");
    EXPECT_EQ(sPost, "-1 1 5 6 4");

    EXPECT_EQ(oAvlTree.Remove(6), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "4 1 -1 5");
    EXPECT_EQ(sMid, "-1 1 4 5");
    EXPECT_EQ(sPost, "-1 1 5 4");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(5), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "1 -1 4");
    EXPECT_EQ(sMid, "-1 1 4");
    EXPECT_EQ(sPost, "-1 4 1");

    EXPECT_EQ(oAvlTree.Remove(5), false);

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-1 4");
    EXPECT_EQ(sMid, "-1 4");
    EXPECT_EQ(sPost, "4 -1");

    EXPECT_EQ(oAvlTree.Remove(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "4");
    EXPECT_EQ(sMid, "4");
    EXPECT_EQ(sPost, "4");

    EXPECT_EQ(oAvlTree.Remove(4), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 0);
    EXPECT_EQ(oAvlTree.GetTree(), nullptr);

    EXPECT_EQ(oAvlTree.Remove(4), false);
}



// LL 无叶子结点
TEST(case_5, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(-1), true);
    EXPECT_EQ(oAvlTree.Insert(-2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);

    EXPECT_EQ(oAvlTree.Insert(-3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-2 -3 -1");
    EXPECT_EQ(sMid, "-3 -2 -1");
    EXPECT_EQ(sPost, "-3 -1 -2");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(-3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-2 -1");
    EXPECT_EQ(sMid, "-2 -1");
    EXPECT_EQ(sPost, "-1 -2");

    EXPECT_EQ(oAvlTree.Remove(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-2");
    EXPECT_EQ(sMid, "-2");
    EXPECT_EQ(sPost, "-2");

    EXPECT_EQ(oAvlTree.Remove(-2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 0);
    EXPECT_EQ(oAvlTree.GetTree(), nullptr);

    EXPECT_EQ(oAvlTree.Remove(1), false);
}

// LL 存在叶子结点, R形删除, RL删除
TEST(case_6, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(-1), true);
    EXPECT_EQ(oAvlTree.Insert(-2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    EXPECT_EQ(oAvlTree.Insert(1), true);
    EXPECT_EQ(oAvlTree.Insert(-3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    EXPECT_EQ(oAvlTree.Insert(-5), true);
    EXPECT_EQ(oAvlTree.Insert(-4), true);
    EXPECT_EQ(oAvlTree.Insert(-6), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-3 -5 -6 -4 -1 -2 1");
    EXPECT_EQ(sMid, "-6 -5 -4 -3 -2 -1 1");
    EXPECT_EQ(sPost, "-6 -4 -5 -2 1 -1 -3");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-3 -5 -6 -4 -1 -2");
    EXPECT_EQ(sMid, "-6 -5 -4 -3 -2 -1");
    EXPECT_EQ(sPost, "-6 -4 -5 -2 -1 -3");

    EXPECT_EQ(oAvlTree.Remove(-2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-3 -5 -6 -4 -1");
    EXPECT_EQ(sMid, "-6 -5 -4 -3 -1");
    EXPECT_EQ(sPost, "-6 -4 -5 -1 -3");

    // 触发LL 进行R删除
    EXPECT_EQ(oAvlTree.Remove(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-5 -6 -3 -4");
    EXPECT_EQ(sMid, "-6 -5 -4 -3");
    EXPECT_EQ(sPost, "-6 -4 -3 -5");

    // 触发RL 进行LR删除
    EXPECT_EQ(oAvlTree.Remove(-6), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-4 -5 -3");
    EXPECT_EQ(sMid, "-5 -4 -3");
    EXPECT_EQ(sPost, "-5 -3 -4");
    
    EXPECT_EQ(oAvlTree.Remove(-4), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-5 -3");
    EXPECT_EQ(sMid, "-5 -3");
    EXPECT_EQ(sPost, "-3 -5");

    EXPECT_EQ(oAvlTree.Remove(-3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-5");
    EXPECT_EQ(sMid, "-5");
    EXPECT_EQ(sPost, "-5");

    EXPECT_EQ(oAvlTree.Remove(-5), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 0);
    EXPECT_EQ(oAvlTree.GetTree(), nullptr);

    EXPECT_EQ(oAvlTree.Remove(1), false);
}


// LL 存在叶子结点, L形删除, LR删除
TEST(case_7, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(-1), true);
    EXPECT_EQ(oAvlTree.Insert(-2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    EXPECT_EQ(oAvlTree.Insert(1), true);
    EXPECT_EQ(oAvlTree.Insert(-3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    EXPECT_EQ(oAvlTree.Insert(-5), true);
    EXPECT_EQ(oAvlTree.Insert(-4), true);
    EXPECT_EQ(oAvlTree.Insert(-6), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-3 -5 -6 -4 -1 -2 1");
    EXPECT_EQ(sMid, "-6 -5 -4 -3 -2 -1 1");
    EXPECT_EQ(sPost, "-6 -4 -5 -2 1 -1 -3");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(-6), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-3 -5 -4 -1 -2 1");
    EXPECT_EQ(sMid, "-5 -4 -3 -2 -1 1");
    EXPECT_EQ(sPost, "-4 -5 -2 1 -1 -3");

    EXPECT_EQ(oAvlTree.Remove(-5), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-3 -4 -1 -2 1");
    EXPECT_EQ(sMid, "-4 -3 -2 -1 1");
    EXPECT_EQ(sPost, "-4 -2 1 -1 -3");

    EXPECT_EQ(oAvlTree.Remove(1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-3 -4 -1 -2");
    EXPECT_EQ(sMid, "-4 -3 -2 -1");
    EXPECT_EQ(sPost, "-4 -2 -1 -3");

    // 触发LR 进行RL删除
    EXPECT_EQ(oAvlTree.Remove(-4), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-2 -3 -1");
    EXPECT_EQ(sMid, "-3 -2 -1");
    EXPECT_EQ(sPost, "-3 -1 -2");

    EXPECT_EQ(oAvlTree.Insert(0), true);
    // // 触发RR 进行L删除
    EXPECT_EQ(oAvlTree.Remove(-3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-1 -2 0");
    EXPECT_EQ(sMid, "-2 -1 0");
    EXPECT_EQ(sPost, "-2 0 -1");
    
    EXPECT_EQ(oAvlTree.Remove(0), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-1 -2");
    EXPECT_EQ(sMid, "-2 -1");
    EXPECT_EQ(sPost, "-2 -1");

    EXPECT_EQ(oAvlTree.Remove(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-2");
    EXPECT_EQ(sMid, "-2");
    EXPECT_EQ(sPost, "-2");

    EXPECT_EQ(oAvlTree.Remove(-2), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 0);
    EXPECT_EQ(oAvlTree.GetTree(), nullptr);

    EXPECT_EQ(oAvlTree.Remove(1), false);
}


//LR 有叶子结点
TEST(case_8, content)
{
    AvlTree<int> oAvlTree;
    EXPECT_EQ(oAvlTree.Insert(5), true);
    EXPECT_EQ(oAvlTree.Insert(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);

    EXPECT_EQ(oAvlTree.Insert(4), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    EXPECT_EQ(oAvlTree.Insert(-2), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    EXPECT_EQ(oAvlTree.Insert(3), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "4 -1 -2 3 5");
    EXPECT_EQ(sMid, "-2 -1 3 4 5");
    EXPECT_EQ(sPost, "-2 3 -1 5 4");

    EXPECT_EQ(oAvlTree.Remove(-2), true); 
    EXPECT_EQ(oAvlTree.GetHeight(), 3);
    
    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "4 -1 3 5");
    EXPECT_EQ(sMid, "-1 3 4 5");
    EXPECT_EQ(sPost, "3 -1 5 4");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(5), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "3 -1 4");
    EXPECT_EQ(sMid, "-1 3 4");
    EXPECT_EQ(sPost, "-1 4 3");

    EXPECT_EQ(oAvlTree.Remove(3), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 2);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-1 4");
    EXPECT_EQ(sMid, "-1 4");
    EXPECT_EQ(sPost, "4 -1");

    // 测试删除节点
    EXPECT_EQ(oAvlTree.Remove(4), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 1);
    sPre.clear(), sMid.clear(), sPost.clear();

    TraverseTreePreNoRecursion(oAvlTree, sPre);
    TraverseTreeMidNoRecursion(oAvlTree, sMid);
    TraverseTreePostNoRecursion(oAvlTree, sPost);

    EXPECT_EQ(sPre, "-1");
    EXPECT_EQ(sMid, "-1");
    EXPECT_EQ(sPost, "-1");


    EXPECT_EQ(oAvlTree.Remove(-1), true);
    EXPECT_EQ(oAvlTree.GetHeight(), 0);
    EXPECT_EQ(oAvlTree.GetTree(), nullptr);

    EXPECT_EQ(oAvlTree.Remove(4), false);
}