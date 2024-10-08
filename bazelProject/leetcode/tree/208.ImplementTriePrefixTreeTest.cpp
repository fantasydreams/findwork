#include "208.ImplementTriePrefixTree.h"
#include "gtest/gtest.h"

TEST(case_1, content)
{
    // Input
    // ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    // [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    // Output
    // [null, null, true, false, true, null, true]

    // Explanation
    // Trie trie = new Trie();
    // trie.insert("apple");
    // trie.search("apple");   // return True
    // trie.search("app");     // return False
    // trie.startsWith("app"); // return True
    // trie.insert("app");
    // trie.search("app");     // return True

    Trie trie;
    trie.insert("apple");
    EXPECT_EQ(trie.search("apple"),true);
    EXPECT_EQ(trie.search("app"),false);     // return False
    EXPECT_EQ(trie.startsWith("app"), true); // return True
    trie.insert("app");
    EXPECT_EQ(trie.search("app"), true);     // return True
    EXPECT_EQ(trie.search("app1"), false);
}


TEST(case_2, content)
{
    Trie1 trie;
    trie.insert("apple");
    EXPECT_EQ(trie.search("apple"),true);
    EXPECT_EQ(trie.search("app"),false);     // return False
    EXPECT_EQ(trie.startsWith("app"), true); // return True
    trie.insert("app");
    EXPECT_EQ(trie.search("app"), true);     // return True
    EXPECT_EQ(trie.search("app1"), false);
}

TEST(case_3, content)
{
    Trie2 trie;
    trie.insert("apple");
    EXPECT_EQ(trie.search("apple"),true);
    EXPECT_EQ(trie.search("app"),false);     // return False
    EXPECT_EQ(trie.startsWith("app"), true); // return True
    trie.insert("app");
    EXPECT_EQ(trie.search("app"), true);     // return True
    EXPECT_EQ(trie.search("app1"), false);
}