#include "203.RemoveLinkedListElements.h"
#include "gtest/gtest.h"

TEST(case_1, content) {
    std::vector<int> a = {1,2,3, 3,4,5};
    std::vector<int> b = {1, 2, 4, 5};
    ListNode * pOrigin = createLinkList(a);
    ListNode * pb = createLinkList(b);
	pOrigin = removeElements(pOrigin, 3);
    bool ans = true;
    EXPECT_EQ(ListValEqual(pb, pOrigin), ans);
    freeLinkList(pOrigin);
    freeLinkList(pb);
}


TEST(case_2, content) {
    std::vector<int> a = {1,2,3, 3,4,5};
    std::vector<int> b = {2,3,3,4,5};
    ListNode * pOrigin = createLinkList(a);
    ListNode * pb = createLinkList(b);
	pOrigin = removeElements(pOrigin, 1);
    bool ans = true;
    EXPECT_EQ(ListValEqual(pb, pOrigin), ans);
    freeLinkList(pOrigin);
    freeLinkList(pb);
}

TEST(case_3, content) {
    std::vector<int> a = {1,2,3, 3,4,5};
    std::vector<int> b = {1, 2, 3, 3, 4};
    ListNode * pOrigin = createLinkList(a);
    ListNode * pb = createLinkList(b);
	pOrigin = removeElements(pOrigin, 5);
    bool ans = true;
    EXPECT_EQ(ListValEqual(pb, pOrigin), ans);
    freeLinkList(pOrigin);
    freeLinkList(pb);
}