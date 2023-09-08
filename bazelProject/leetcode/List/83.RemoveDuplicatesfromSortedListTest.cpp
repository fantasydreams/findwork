#include "83.RemoveDuplicatesfromSortedList.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    vector<int> vec = {-100,1,1,1,2,100,100};
    vector<int> ans = {-100,1,2,100};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_2,content)
{
    vector<int> vec = {};
    ListNode * pO = createLinkList(vec);
    ListNode * pAns = deleteDuplicates(pO);
    EXPECT_EQ((bool)pAns, false);
}

TEST(case_3,content)
{
    vector<int> vec = {1,2,3};
    vector<int> ans = {1,2,3};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates(pO);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}

TEST(case_4,content)
{
    vector<int> vec = {-100,1,1,1,2,100,100};
    vector<int> ans = {-100,1,2,100};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates1(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_5,content)
{
    vector<int> vec = {};
    ListNode * pO = createLinkList(vec);
    ListNode * pAns = deleteDuplicates1(pO);
    EXPECT_EQ((bool)pAns, false);
}

TEST(case_6,content)
{
    vector<int> vec = {1,2,3};
    vector<int> ans = {1,2,3};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates1(pO);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}

TEST(case_41,content)
{
    vector<int> vec = {-100,1,1,1,2,100,100};
    vector<int> ans = {-100,1,2,100};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_51,content)
{
    vector<int> vec = {};
    ListNode * pO = createLinkList(vec);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ((bool)pAns, false);
}

TEST(case_61,content)
{
    vector<int> vec = {1,2,3};
    vector<int> ans = {1,2,3};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_42,content)
{
    vector<int> vec = {-100,1,1,1,2,100,100};
    vector<int> ans = {-100,1,2,100};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates3(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_52,content)
{
    vector<int> vec = {};
    ListNode * pO = createLinkList(vec);
    ListNode * pAns = deleteDuplicates3(pO);
    printList(pAns);
    EXPECT_EQ((bool)pAns, false);
}

TEST(case_62,content)
{
    vector<int> vec = {1,2,3};
    vector<int> ans = {1,2,3};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates3(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}