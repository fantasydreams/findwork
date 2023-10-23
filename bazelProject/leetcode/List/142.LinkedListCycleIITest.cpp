#include "142.LinkedListCycleII.h"
#include "gtest/gtest.h"


//一样长
TEST(case_1,content)
{
    std::vector<int> a = {2,4,3};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycle(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 4);
    freeCircleLinkList(pCircle);
}

TEST(case_2,content)
{
    std::vector<int> a = {3,2,0,-4};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycle(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 2);
    freeCircleLinkList(pCircle);
}

TEST(case_3,content)
{
    std::vector<int> a = {1,2};
    ListNode * pCircle = createCircleLinkList(a, 0);
	ListNode * pNode = detectCycle(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 1);
    freeCircleLinkList(pCircle);
}

TEST(case_4,content)
{
    std::vector<int> a = {1};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycle(pCircle);
    EXPECT_EQ((bool)pNode, 0);
    freeCircleLinkList(pCircle);
}


TEST(case_11,content)
{
    std::vector<int> a = {2,4,3};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycle1(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 4);
    freeCircleLinkList(pCircle);
}

TEST(case_21,content)
{
    std::vector<int> a = {3,2,0,-4};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycle1(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 2);
    freeCircleLinkList(pCircle);
}

TEST(case_31,content)
{
    std::vector<int> a = {1,2};
    ListNode * pCircle = createCircleLinkList(a, 0);
	ListNode * pNode = detectCycle1(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 1);
    freeCircleLinkList(pCircle);
}

TEST(case_41,content)
{
    std::vector<int> a = {1};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycle1(pCircle);
    EXPECT_EQ((bool)pNode, 0);
    freeCircleLinkList(pCircle);
}

TEST(case_12,content)
{
    std::vector<int> a = {2,4,3};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycleHash(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 4);
    freeCircleLinkList(pCircle);
}

TEST(case_22,content)
{
    std::vector<int> a = {3,2,0,-4};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycleHash(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 2);
    freeCircleLinkList(pCircle);
}

TEST(case_32,content)
{
    std::vector<int> a = {1,2};
    ListNode * pCircle = createCircleLinkList(a, 0);
	ListNode * pNode = detectCycleHash(pCircle);
    EXPECT_EQ((bool)pNode, 1);
    EXPECT_EQ(pNode->val, 1);
    freeCircleLinkList(pCircle);
}

TEST(case_42,content)
{
    std::vector<int> a = {1};
    ListNode * pCircle = createCircleLinkList(a, 1);
	ListNode * pNode = detectCycleHash(pCircle);
    EXPECT_EQ((bool)pNode, 0);
    freeCircleLinkList(pCircle);
}