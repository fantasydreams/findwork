#include "92.ReverseLinkedListII.h"
#include "linkcomm.h"
#include "gtest/gtest.h"


//一样长
TEST(case_1,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 2, right = 4;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween(pOrigin, left, right);
    printList(p);
    std::vector<int> ans = {1,4,3,2,5};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}


TEST(case_2,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 1, right = 5;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween(pOrigin, left, right);
    
    std::vector<int> ans = {5,4,3,2,1};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}

TEST(case_3,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 1, right = 1;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween(pOrigin, left, right);
    
    std::vector<int> ans = {1,2,3,4,5};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}

TEST(case_4,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 2, right = 2;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween(pOrigin, left, right);
    
    std::vector<int> ans = {1,2,3,4,5};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}

TEST(case_5,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 5, right = 5;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween(pOrigin, left, right);
    
    std::vector<int> ans = {1,2,3,4,5};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}


TEST(case_11,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 2, right = 4;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween(pOrigin, left, right);
    printList(p);
    std::vector<int> ans = {1,4,3,2,5};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}


TEST(case_12,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 1, right = 5;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween1(pOrigin, left, right);
    
    std::vector<int> ans = {5,4,3,2,1};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}

TEST(case_13,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 1, right = 1;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween1(pOrigin, left, right);
    
    std::vector<int> ans = {1,2,3,4,5};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}

TEST(case_14,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 2, right = 2;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween1(pOrigin, left, right);
    
    std::vector<int> ans = {1,2,3,4,5};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}

TEST(case_15,content)
{
    std::vector<int> a = {1,2,3,4,5};
    int left = 5, right = 5;

    ListNode* pOrigin = createLinkList(a);
    ListNode* p = reverseBetween1(pOrigin, left, right);
    
    std::vector<int> ans = {1,2,3,4,5};
    ListNode* pAns = createLinkList(ans);
    EXPECT_EQ(ListValEqual(p, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p);
}