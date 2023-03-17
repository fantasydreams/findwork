#include "328.OddEvenLinkedList.h"
#include "gtest/gtest.h"


TEST(case_1,content)
{
    std::vector<int> a = {1,2,0};
    std::vector<int> ans = {1,0,2};
    ListNode * head = createLinkList(a);
    ListNode * pAns = createLinkList(ans);
    ListNode * pCalc = oddEvenList(head);
    
    EXPECT_EQ(ListValEqual(pAns, pCalc), true);
    freeLinkList(pCalc);
    freeLinkList(pAns);
}

TEST(case_2,content)
{
    std::vector<int> a = {1};
    std::vector<int> ans = {1};
    ListNode * head = createLinkList(a);
    ListNode * pAns = createLinkList(ans);
    ListNode * pCalc = oddEvenList(head);
    
    EXPECT_EQ(ListValEqual(pAns, pCalc), true);
    freeLinkList(pCalc);
    freeLinkList(pAns);
}

TEST(case_3,content)
{
    std::vector<int> a = {1,2,3,4,5,6,7};
    std::vector<int> ans = {1,3,5,7,2,4,6};
    ListNode * head = createLinkList(a);
    ListNode * pAns = createLinkList(ans);
    ListNode * pCalc = oddEvenList(head);
    
    EXPECT_EQ(ListValEqual(pAns, pCalc), true);
    freeLinkList(pCalc);
    freeLinkList(pAns);
}