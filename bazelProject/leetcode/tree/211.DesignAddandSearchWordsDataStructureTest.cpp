#include "211.DesignAddandSearchWordsDataStructure.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    WordDictionary oDict;
    oDict.addWord("bad");
    EXPECT_EQ(oDict.search("bad"), true);
    EXPECT_EQ(oDict.search("dad"), false);
    oDict.addWord("dad");
    EXPECT_EQ(oDict.search("dad"), true);

    EXPECT_EQ(oDict.search("mad"), false);
    oDict.addWord("mad"); 
    EXPECT_EQ(oDict.search("mad"), true); 
    EXPECT_EQ(oDict.search("pad"), false); 
    EXPECT_EQ(oDict.search("bad"), true); 
    EXPECT_EQ(oDict.search(".ad"), true); 
    EXPECT_EQ(oDict.search("b.."), true); 
}


TEST(case_2, content) {
    WordDictionary1 oDict;
    oDict.addWord("bad");
    EXPECT_EQ(oDict.search("bad"), true);
    EXPECT_EQ(oDict.search("dad"), false);
    oDict.addWord("dad");
    EXPECT_EQ(oDict.search("dad"), true);

    EXPECT_EQ(oDict.search("mad"), false);
    oDict.addWord("mad"); 
    EXPECT_EQ(oDict.search("mad"), true); 
    EXPECT_EQ(oDict.search("pad"), false); 
    EXPECT_EQ(oDict.search("bad"), true); 
    EXPECT_EQ(oDict.search(".ad"), true); 
    EXPECT_EQ(oDict.search("b.."), true); 
}