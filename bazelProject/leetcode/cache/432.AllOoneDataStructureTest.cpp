#include "432.AllOoneDataStructure.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    // Input
    // ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
    // [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
    // Output
    // [null, null, null, "hello", "hello", null, "hello", "leet"]

    // Explanation
    // AllOne allOne = new AllOne();
    // allOne.inc("hello");
    // allOne.inc("hello");
    // allOne.getMaxKey(); // return "hello"
    // allOne.getMinKey(); // return "hello"
    // allOne.inc("leet");
    // allOne.getMaxKey(); // return "hello"
    // allOne.getMinKey(); // return "leet"
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("hello");
    EXPECT_EQ(allOne.getMaxKey(), "hello"); // return "hello"
    EXPECT_EQ(allOne.getMinKey(), "hello"); // return "hello"
    allOne.inc("leet");
    EXPECT_EQ(allOne.getMaxKey(), "hello"); // return "hello"
    EXPECT_EQ(allOne.getMinKey(), "leet"); // return "leet"
    
}

TEST(case_2,content)
{
    AllOne allOne;
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("b");
    allOne.dec("b");
    allOne.dec("b");
    EXPECT_EQ(allOne.getMaxKey(), "b"); // return "hello"
    EXPECT_EQ(allOne.getMinKey(), "a"); // return "hello"

    allOne.dec("b");
    EXPECT_EQ(allOne.getMaxKey(), "b"); // return "hello"
    EXPECT_EQ(allOne.getMinKey(), "b"); // return "hello"
}