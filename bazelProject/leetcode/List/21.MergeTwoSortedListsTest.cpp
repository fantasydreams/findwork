#include "21.MergeTwoSortedLists.h"
#include "gtest/gtest.h"


//一样长
TEST(case_1,content)
{
    std::vector<int> a = {2,3,4}, b = {1}, ans = {1,2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pb = createLinkList(b);
    ListNode * pans = createLinkList(ans);
    
    ListNode * pmerge = mergeTwoLists(pa, pb);

    EXPECT_EQ(ListValEqual(pans, pmerge), true);
}


TEST(case_2,content)
{
    std::vector<int> a = {2,3,4}, b = {1}, ans = {1,2,3,4};
    ListNode * pa = createLinkList(a);
    ListNode * pb = createLinkList(b);
    ListNode * pans = createLinkList(ans);
    
    ListNode * pmerge = mergeTwoLists1(pa, pb);

    EXPECT_EQ(ListValEqual(pans, pmerge), true);
}