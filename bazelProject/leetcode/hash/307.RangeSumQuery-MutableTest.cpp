#include "307.RangeSumQuery-Mutable.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    // Input
    // ["NumArray", "sumRange", "update", "sumRange"]
    // [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
    // Output
    // [null, 9, null, 8]

    vector<int> vec = {1, 3, 5};
    NumArray obj(vec);
    
    EXPECT_EQ(obj.sumRange(0, 2), 9);
    obj.update(1,2);

    EXPECT_EQ(obj.sumRange(0, 2), 8);
}



TEST(case_2,content)
{
    // ["NumArray","update","update","update","sumRange","update","sumRange","update","sumRange","sumRange","update"]
    // [[[7,2,7,2,0]],[4,6],[0,2],   [0,9],   [4,4],     [3,8],   [0,4],     [4,1],   [0,3],[0,4],[0,4]]

    vector<int> vec = {7,2,7,2,0};
    NumArray obj(vec);
    obj.update(4,6);
    obj.update(0,2);
    obj.update(0,9);
    EXPECT_EQ(obj.sumRange(4, 4), 6);
    obj.update(3,8);
    EXPECT_EQ(obj.sumRange(0, 4), 32);
    obj.update(4,1);
    EXPECT_EQ(obj.sumRange(0, 3), 26);
    EXPECT_EQ(obj.sumRange(0, 4), 27);
    obj.update(0,4);
}