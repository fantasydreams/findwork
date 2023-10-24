#include "146.LRUCache.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    // LRUCache lRUCache = new LRUCache(2);
    // lRUCache.put(1, 1); // cache is {1=1}
    // lRUCache.put(2, 2); // cache is {1=1, 2=2}
    // lRUCache.get(1);    // return 1
    // lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // lRUCache.get(2);    // returns -1 (not found)
    // lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    // lRUCache.get(1);    // return -1 (not found)
    // lRUCache.get(3);    // return 3
    // lRUCache.get(4);    // return 4
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

// ["LRUCache","put","put","get","put","put","get"]
// [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
TEST(case_2,content)
{
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(2), 2);
    cache.put(1, 1);
    cache.put(4, 1);
    EXPECT_EQ(cache.get(2), -1);
}

TEST(case_3,content)
{
    // LRUCache lRUCache = new LRUCache(2);
    // lRUCache.put(1, 1); // cache is {1=1}
    // lRUCache.put(2, 2); // cache is {1=1, 2=2}
    // lRUCache.get(1);    // return 1
    // lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // lRUCache.get(2);    // returns -1 (not found)
    // lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    // lRUCache.get(1);    // return -1 (not found)
    // lRUCache.get(3);    // return 3
    // lRUCache.get(4);    // return 4
    LRUCache1 cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

// ["LRUCache","put","put","get","put","put","get"]
// [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
TEST(case_4,content)
{
    LRUCache1 cache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(2), 2);
    cache.put(1, 1);
    cache.put(4, 1);
    EXPECT_EQ(cache.get(2), -1);
}


TEST(case_5,content)
{
    // LRUCache lRUCache = new LRUCache(2);
    // lRUCache.put(1, 1); // cache is {1=1}
    // lRUCache.put(2, 2); // cache is {1=1, 2=2}
    // lRUCache.get(1);    // return 1
    // lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    // lRUCache.get(2);    // returns -1 (not found)
    // lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    // lRUCache.get(1);    // return -1 (not found)
    // lRUCache.get(3);    // return 3
    // lRUCache.get(4);    // return 4
    LRUCache2 cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}

// ["LRUCache","put","put","get","put","put","get"]
// [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
TEST(case_6,content)
{
    LRUCache2 cache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(2), 2);
    cache.put(1, 1);
    cache.put(4, 1);
    EXPECT_EQ(cache.get(2), -1);
}