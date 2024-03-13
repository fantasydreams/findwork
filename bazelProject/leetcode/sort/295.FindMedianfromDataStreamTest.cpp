#include "295.FindMedianfromDataStream.h"
#include "gtest/gtest.h"

TEST(case1, content) {
    MedianFinder m;
    m.addNum(1);
    EXPECT_EQ(m.findMedian(), 1);
    m.addNum(2);
    EXPECT_EQ(m.findMedian(), 1.5);
    m.addNum(3);
    EXPECT_EQ(m.findMedian(), 2);
}