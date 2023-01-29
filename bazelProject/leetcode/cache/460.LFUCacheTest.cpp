#include "460.LFUCache.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    // cnt(x) = the use counter for key x
    // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
    // LFUCache lfu = new LFUCache(2);
    // lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    // lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    // lfu.get(1);      // return 1
    //                  // cache=[1,2], cnt(2)=1, cnt(1)=2
    // lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
    //                  // cache=[3,1], cnt(3)=1, cnt(1)=2
    // lfu.get(2);      // return -1 (not found)
    // lfu.get(3);      // return 3
    //                  // cache=[3,1], cnt(3)=2, cnt(1)=2
    // lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
    //                  // cache=[4,3], cnt(4)=1, cnt(3)=2
    // lfu.get(1);      // return -1 (not found)
    // lfu.get(3);      // return 3
    //                  // cache=[3,4], cnt(4)=1, cnt(3)=3
    // lfu.get(4);      // return 4
    //                  // cache=[4,3], cnt(4)=2, cnt(3)=3
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(3), 3);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}


TEST(case_2,content)
{
    // ["LFUCache","put","get"]
    // [[0],[0,0],[0]]
    LFUCache cache(0);
    cache.put(0, 0);
    EXPECT_EQ(cache.get(0), -1);
}