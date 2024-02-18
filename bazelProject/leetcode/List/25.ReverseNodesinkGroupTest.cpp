#include "25.ReverseNodesinkGroup.h"
#include "linkcomm.h"
#include "gtest/gtest.h"


//一样长
TEST(case_1,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {4,3,2};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 3;
    ListNode * pres = reverseKGroup(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_2,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {3,2,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 2;
    ListNode * pres = reverseKGroup(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_3,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 1;
    ListNode * pres = reverseKGroup(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_4,content)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 4;
    ListNode * pres = reverseKGroup(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_1,content1)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {4,3,2};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 3;
    ListNode * pres = reverseKGroup1(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_2,content1)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {3,2,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 2;
    ListNode * pres = reverseKGroup1(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_3,content1)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 1;
    ListNode * pres = reverseKGroup1(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_4,content1)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 4;
    ListNode * pres = reverseKGroup1(pa, k);
    // printList(pres);
    EXPECT_EQ(ListValEqual(pans, pres), true);
}


TEST(case_1,content2)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {4,3,2};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 3;
    ListNode * pres = reverseKGroup2(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_2,content2)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {3,2,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 2;
    ListNode * pres = reverseKGroup2(pa, k);
    printList(pres);
    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_3,content2)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 1;
    ListNode * pres = reverseKGroup2(pa, k);

    EXPECT_EQ(ListValEqual(pans, pres), true);
}

TEST(case_4,content2)
{
    std::vector<int> a = {2,3,4};
    std::vector<int> ans = {2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);

    int k = 4;
    ListNode * pres = reverseKGroup2(pa, k);
    // printList(pres);
    EXPECT_EQ(ListValEqual(pans, pres), true);
}