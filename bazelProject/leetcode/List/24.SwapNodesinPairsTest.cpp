#include "24.SwapNodesinPairs.h"
#include "gtest/gtest.h"


//一样长
TEST(case_1,content)
{
    std::vector<int> a = {2,3,4}, ans = {3,2,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    
    ListNode * pswap = swapPairs(pa);
    // printList(pswap);
    EXPECT_EQ(ListValEqual(pswap, pans), true);
    freeLinkList(pswap);
    freeLinkList(pans);
}


TEST(case_2,content)
{
    std::vector<int> a = {2,3,4,5}, ans = {3,2,5,4};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    
    ListNode * pswap = swapPairs(pa);
    // printList(pswap);
    EXPECT_EQ(ListValEqual(pswap, pans), true);
    freeLinkList(pswap);
    freeLinkList(pans);
}

TEST(case_3,content)
{
    std::vector<int> a = {2}, ans = {2};
    ListNode * pa = createLinkList(a);
    ListNode * pans = createLinkList(ans);
    
    ListNode * pswap = swapPairs(pa);
    // printList(pswap);
    EXPECT_EQ(ListValEqual(pswap, pans), true);
    freeLinkList(pswap);
    freeLinkList(pans);
}

TEST(case_4,content)
{
    std::vector<int> a = {2}, ans = {2};
    ListNode * pa = nullptr;
    ListNode * pans = nullptr;
    
    ListNode * pswap = swapPairs(pa);
    // printList(pswap);
    EXPECT_EQ(ListValEqual(pswap, pans), true);
    freeLinkList(pswap);
    freeLinkList(pans);
}