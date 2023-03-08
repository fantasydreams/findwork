#include "232.ImplementQueueusingStacks.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    //["MyQueue", "push", "push", "peek", "pop", "empty"]
    //[[], [1], [2], [], [], []]
    MyQueue q;
    q.push(1);
    q.push(2);
    EXPECT_EQ(q.peek(), 1);
    EXPECT_EQ(q.empty(), false);
    q.pop();
    EXPECT_EQ(q.peek(), 2);
    EXPECT_EQ(q.empty(), false);
    q.pop();
    EXPECT_EQ(q.empty(), true);
    q.push(3);
    EXPECT_EQ(q.empty(), false);
    EXPECT_EQ(q.peek(), 3);
    EXPECT_EQ(q.empty(), false);
    q.pop();
    EXPECT_EQ(q.empty(), true);
}
