#include "gtest/gtest.h"
#include <vector>
#include <cstdlib>
#include <cmath>
#include "bintree.h"
#include "bintreetools.h"


TEST(case_1, content)
{
    BinTree<int> oBinTree;
    EXPECT_EQ(oBinTree.Insert(1), true);
    EXPECT_EQ(oBinTree.Insert(1), false);

    std::string sList = "1";
    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    // oBinTree.Destroy();

    EXPECT_EQ(sPre, sList);
    EXPECT_EQ(sMid, sList);
    EXPECT_EQ(sPost, sList);

    EXPECT_EQ(oBinTree.Remove(1), true);
    EXPECT_EQ(oBinTree.Remove(1), false);

    sList.clear();
    sPre.clear();
    sMid.clear();
    sPost.clear();

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    // oBinTree.Destroy();

    EXPECT_EQ(sPre, sList);
    EXPECT_EQ(sMid, sList);
    EXPECT_EQ(sPost, sList);
}


TEST(case_2, content)
{
    BinTree<int> oBinTree;
    EXPECT_EQ(oBinTree.Insert(1), true);
    EXPECT_EQ(oBinTree.Insert(1), false);
    EXPECT_EQ(oBinTree.Insert(2), true); 

    std::string sList = "1";
    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    EXPECT_EQ(sPre, "1 2");
    EXPECT_EQ(sMid, "1 2");
    EXPECT_EQ(sPost, "2 1");

    // oBinTree.Destroy();
    EXPECT_EQ(oBinTree.Remove(2), true);  

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    EXPECT_EQ(sPre, sList);
    EXPECT_EQ(sMid, sList);
    EXPECT_EQ(sPost, sList);

    EXPECT_EQ(oBinTree.Remove(1), true);
    EXPECT_EQ(oBinTree.Remove(1), false);

    sList.clear();
    sPre.clear();
    sMid.clear();
    sPost.clear();

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    // oBinTree.Destroy();

    EXPECT_EQ(sPre, sList);
    EXPECT_EQ(sMid, sList);
    EXPECT_EQ(sPost, sList);
}


TEST(case_3, content)
{
    BinTree<int> oBinTree;
    EXPECT_EQ(oBinTree.Insert(1), true);
    EXPECT_EQ(oBinTree.Insert(1), false);
    EXPECT_EQ(oBinTree.Insert(2), true); 

    std::string sList = "1";
    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    EXPECT_EQ(sPre, "1 2");
    EXPECT_EQ(sMid, "1 2");
    EXPECT_EQ(sPost, "2 1");

    // oBinTree.Destroy();
    EXPECT_EQ(oBinTree.Remove(1), true);  

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    EXPECT_EQ(sPre, "2");
    EXPECT_EQ(sMid, "2");
    EXPECT_EQ(sPost, "2");

    EXPECT_EQ(oBinTree.Remove(2), true);
    EXPECT_EQ(oBinTree.Remove(2), false);

    sList.clear();
    sPre.clear();
    sMid.clear();
    sPost.clear();

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    // oBinTree.Destroy();

    EXPECT_EQ(sPre, sList);
    EXPECT_EQ(sMid, sList);
    EXPECT_EQ(sPost, sList);
}


TEST(case_4, content)
{
    BinTree<int> oBinTree;
    EXPECT_EQ(oBinTree.Insert(1), true);
    EXPECT_EQ(oBinTree.Insert(1), false);
    EXPECT_EQ(oBinTree.Insert(3), true); 
    EXPECT_EQ(oBinTree.Insert(2), true);  
    EXPECT_EQ(oBinTree.Insert(4), true);  
    EXPECT_EQ(oBinTree.Insert(-1), true);  
    EXPECT_EQ(oBinTree.Insert(-2), true);   
    EXPECT_EQ(oBinTree.Insert(0), true);   

    TraverseTreeLevelDebug(oBinTree);

    std::string sPre, sMid, sPost;
    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    EXPECT_EQ(sPre, "1 -1 -2 0 3 2 4");
    EXPECT_EQ(sMid, "-2 -1 0 1 2 3 4");
    EXPECT_EQ(sPost, "-2 0 -1 2 4 3 1");

    // // oBinTree.Destroy();
    EXPECT_EQ(oBinTree.Remove(-2), true);  

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);

    EXPECT_EQ(sPre, "1 -1 0 3 2 4");
    EXPECT_EQ(sMid, "-1 0 1 2 3 4");
    EXPECT_EQ(sPost, "0 -1 2 4 3 1");

    EXPECT_EQ(oBinTree.Remove(3), true);
    EXPECT_EQ(oBinTree.Remove(3), false);

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost);


    EXPECT_EQ(sPre, "1 -1 0 4 2");
    EXPECT_EQ(sMid, "-1 0 1 2 4");
    EXPECT_EQ(sPost, "0 -1 2 4 1");

    EXPECT_EQ(oBinTree.Remove(1), true);
    EXPECT_EQ(oBinTree.Remove(1), false);

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost); 

    EXPECT_EQ(sPre, "2 -1 0 4");
    EXPECT_EQ(sMid, "-1 0 2 4");
    EXPECT_EQ(sPost, "0 -1 4 2");


    EXPECT_EQ(oBinTree.Remove(4), true);   
    EXPECT_EQ(oBinTree.Insert(5), true);  
    EXPECT_EQ(oBinTree.Insert(3), true);  
    EXPECT_EQ(oBinTree.Insert(4), true);  

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost); 

    EXPECT_EQ(sPre, "2 -1 0 5 3 4");
    EXPECT_EQ(sMid, "-1 0 2 3 4 5");
    EXPECT_EQ(sPost, "0 -1 4 3 5 2");

    EXPECT_EQ(oBinTree.Remove(2), true);   

    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost); 

    EXPECT_EQ(sPre, "3 -1 0 5 4");
    EXPECT_EQ(sMid, "-1 0 3 4 5");
    EXPECT_EQ(sPost, "0 -1 4 5 3");

    EXPECT_EQ(oBinTree.Remove(-1), true);    
    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost); 

    EXPECT_EQ(sPre, "3 0 5 4");
    EXPECT_EQ(sMid, "0 3 4 5");
    EXPECT_EQ(sPost, "0 4 5 3");
    

    EXPECT_EQ(oBinTree.Remove(4), true);    
    EXPECT_EQ(oBinTree.Remove(0), true);     
    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost); 

    EXPECT_EQ(sPre, "3 5");
    EXPECT_EQ(sMid, "3 5");
    EXPECT_EQ(sPost, "5 3");

    EXPECT_EQ(oBinTree.Remove(3), true);    
    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost); 

    EXPECT_EQ(sPre, "5");
    EXPECT_EQ(sMid, "5");
    EXPECT_EQ(sPost, "5");

    EXPECT_EQ(oBinTree.Remove(5), true);    
    TraverseTreePreNoRecursion(oBinTree, sPre);
    TraverseTreeMidNoRecursion(oBinTree, sMid);
    TraverseTreePostNoRecursion(oBinTree, sPost); 

    EXPECT_EQ(sPre, "");
    EXPECT_EQ(sMid, "");
    EXPECT_EQ(sPost, "");
}