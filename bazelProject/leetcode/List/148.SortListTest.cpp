#include "148.SortList.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> linkvec = {123,32,23,5,7,1,2,3,4,5};
    std::vector<int> con = {1,2,3,4,5,5,7,23,32,123};
	ListNode * pRes = createLinkList(con);
    ListNode * pSort = createLinkList(linkvec);
    ListNode * pSorted = sortList(pSort);
    
    // printList(pSorted);
    EXPECT_EQ(ListValEqual(pSorted, pRes), true);
    freeLinkList(pSorted);
    freeLinkList(pRes);
}

TEST(case_2,content)
{
    std::vector<int> linkvec = {123,32,23,5,7,1,2,3,4,5};
    std::vector<int> con = {1,2,3,4,5,5,7,23,32,123};
	ListNode * pRes = createLinkList(con);
    ListNode * pSort = createLinkList(linkvec);
    ListNode * pSorted = sortListMergeSort(pSort);
    
    // printList(pSorted);
    EXPECT_EQ(ListValEqual(pSorted, pRes), true);
    freeLinkList(pSorted);
    freeLinkList(pRes);
}