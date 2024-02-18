#include "155.MinStack.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    //["MinStack","push","push","push","getMin","pop","top","getMin"]
    //[[],[-2],[0],[-3],[],[],[],[]]

    MinStack mSt;
    mSt.push(-2);
    EXPECT_EQ(mSt.top(), -2);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.push(0);
    EXPECT_EQ(mSt.top(), 0);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.push(-3);
    EXPECT_EQ(mSt.top(), -3);
    EXPECT_EQ(mSt.getMin(), -3);

    mSt.pop();
    EXPECT_EQ(mSt.top(), 0);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.pop();
    EXPECT_EQ(mSt.top(), -2);
    EXPECT_EQ(mSt.getMin(), -2);
}


TEST(case_3,content)
{
    //["MinStack","push","push","push","getMin","pop","top","getMin"]
    //[[],[-2],[0],[-3],[],[],[],[]]

    MinStack1 mSt;
    mSt.push(-2);
    EXPECT_EQ(mSt.top(), -2);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.push(0);
    EXPECT_EQ(mSt.top(), 0);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.push(-3);
    EXPECT_EQ(mSt.top(), -3);
    EXPECT_EQ(mSt.getMin(), -3);

    mSt.pop();
    EXPECT_EQ(mSt.top(), 0);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.pop();
    EXPECT_EQ(mSt.top(), -2);
    EXPECT_EQ(mSt.getMin(), -2);
}


TEST(case_4,content)
{
    //["MinStack","push","push","push","getMin","pop","top","getMin"]
    //[[],[-2],[0],[-3],[],[],[],[]]

    MinStack2 mSt;
    mSt.push(-2);
    EXPECT_EQ(mSt.top(), -2);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.push(0);
    EXPECT_EQ(mSt.top(), 0);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.push(-3);
    EXPECT_EQ(mSt.top(), -3);
    EXPECT_EQ(mSt.getMin(), -3);

    mSt.pop();
    EXPECT_EQ(mSt.top(), 0);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.pop();
    EXPECT_EQ(mSt.top(), -2);
    EXPECT_EQ(mSt.getMin(), -2);
}


TEST(case_5,content)
{
    //["MinStack","push","push","push","getMin","pop","top","getMin"]
    //[[],[-2],[0],[-3],[],[],[],[]]

    MinStack3 mSt;
    mSt.push(-2);
    EXPECT_EQ(mSt.top(), -2);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.push(0);
    EXPECT_EQ(mSt.top(), 0);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.push(-3);
    EXPECT_EQ(mSt.top(), -3);
    EXPECT_EQ(mSt.getMin(), -3);

    mSt.pop();
    EXPECT_EQ(mSt.top(), 0);
    EXPECT_EQ(mSt.getMin(), -2);

    mSt.pop();
    EXPECT_EQ(mSt.top(), -2);
    EXPECT_EQ(mSt.getMin(), -2);
}