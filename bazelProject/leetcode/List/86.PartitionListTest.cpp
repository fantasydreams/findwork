#include "86.PartitionList.h"
#include "linkcomm.h"
#include "gtest/gtest.h"
#include <vector>


TEST(case_1,content)
{
    std::vector<int> a = {1,4,3,2,5,2};
    std::vector<int> ans = {1,2,2,4,3,5};
    int x = 3;
    ListNode * pList = createLinkList(a);
	ListNode * pRes = partition(pList, x);
    ListNode * pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(pRes, pAns), true);
}

TEST(case_2,content)
{
    std::vector<int> a = {2, 1};
    std::vector<int> ans = {1, 2};
    int x = 2;
    ListNode * pList = createLinkList(a);
	ListNode * pRes = partition(pList, x);
    ListNode * pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(pRes, pAns), true);
}

TEST(case_3,content)
{
    std::vector<int> a = {2, 1};
    int x = 3;
    ListNode * pList = createLinkList(a);
	ListNode * pRes = partition(pList, x);
    ListNode * pAns = createLinkList(a);
    EXPECT_EQ(ListValEqual(pRes, pAns), true);
}

TEST(case_1,content1)
{
    std::vector<int> a = {1,4,3,2,5,2};
    std::vector<int> ans = {1,2,2,4,3,5};
    int x = 3;
    ListNode * pList = createLinkList(a);
	ListNode * pRes = partition1(pList, x);
    ListNode * pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(pRes, pAns), true);
}

TEST(case_2,content1)
{
    std::vector<int> a = {2, 1};
    std::vector<int> ans = {1, 2};
    int x = 2;
    ListNode * pList = createLinkList(a);
	ListNode * pRes = partition1(pList, x);
    ListNode * pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(pRes, pAns), true);
}

TEST(case_3,content1)
{
    std::vector<int> a = {2, 1};
    int x = 3;
    ListNode * pList = createLinkList(a);
	ListNode * pRes = partition1(pList, x);
    ListNode * pAns = createLinkList(a);
    EXPECT_EQ(ListValEqual(pRes, pAns), true);
}