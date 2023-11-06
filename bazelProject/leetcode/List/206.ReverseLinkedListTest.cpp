#include "206.ReverseLinkedList.h"
#include "gtest/gtest.h"


//一样长
TEST(case_1,content)
{
    std::vector<int> a = {1,2,3,4,5};
    std::vector<int> b = {5,4,3,2,1};
    ListNode * pOrigin = createLinkList(a);
    ListNode * pb = createLinkList(b);
	pOrigin = reverseList(pOrigin);
    bool ans = true;
    EXPECT_EQ(ListValEqual(pb, pOrigin), ans);
    freeCircleLinkList(pOrigin);
    freeCircleLinkList(pb);
}

TEST(case_2,content)
{
    std::vector<int> a = {1,2,3,4,5};
    std::vector<int> b = {5,4,3,2,1};
    ListNode * pOrigin = createLinkList(a);
    ListNode * pb = createLinkList(b);
	pOrigin = reverseList1(pOrigin);
    bool ans = true;
    EXPECT_EQ(ListValEqual(pb, pOrigin), ans);
    freeCircleLinkList(pOrigin);
    freeCircleLinkList(pb);
}