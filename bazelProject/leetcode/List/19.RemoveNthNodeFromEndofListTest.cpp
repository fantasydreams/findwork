#include "19.RemoveNthNodeFromEndofList.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    ListNode * pdel = removeNthFromEnd(pa, 1);

    EXPECT_EQ(ListValEqual(pans, pdel), true);
    freeLinkList(pdel);
    freeLinkList(pans);
}

TEST(case_2,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    ListNode * pdel = removeNthFromEnd(pa, 2);

    EXPECT_EQ(ListValEqual(pans, pdel), true);
    freeLinkList(pdel);
    freeLinkList(pans);
}

TEST(case_3,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    ListNode * pdel = removeNthFromEnd(pa, 3);
    printList(pdel);
    EXPECT_EQ(ListValEqual(pans, pdel), true);
    freeLinkList(pdel);
    freeLinkList(pans);
}


TEST(case_4,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    ListNode * pdel = removeNthFromEnd1(pa, 1);

    EXPECT_EQ(ListValEqual(pans, pdel), true);
    freeLinkList(pdel);
    freeLinkList(pans);
}

TEST(case_5,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    ListNode * pdel = removeNthFromEnd1(pa, 2);

    EXPECT_EQ(ListValEqual(pans, pdel), true);
    freeLinkList(pdel);
    freeLinkList(pans);
}

TEST(case_6,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    ListNode * pdel = removeNthFromEnd1(pa, 3);
    printList(pdel);
    EXPECT_EQ(ListValEqual(pans, pdel), true);
    freeLinkList(pdel);
    freeLinkList(pans);
}


TEST(case_7,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    ListNode * pdel = removeNthFromEnd1(pa, 4);
    printList(pdel);
    EXPECT_EQ(ListValEqual(pans, pdel), true);
    freeLinkList(pdel);
    freeLinkList(pans);
}