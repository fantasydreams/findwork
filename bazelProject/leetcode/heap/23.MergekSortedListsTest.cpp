#include "23.MergekSortedLists.h"
#include "gtest/gtest.h"

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

TEST(case_1,content)
{
    std::vector<int> a = {2,3,3,6};
    std::vector<int> b = {1,2,7,9};
    std::vector<int> c = {1,2,2,3,3,6,7,9};
	ListNode * lista = createLinkList(a);
    ListNode * listb = createLinkList(b);
    ListNode * listc = createLinkList(c);
    
    vector<ListNode*> lists = {lista, listb};
    ListNode * listAns = mergeKLists(lists);
    printList(listAns);
    bool ans = true;
    EXPECT_EQ(ListValEqual(listc, listAns), ans);
}