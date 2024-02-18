#include "82.RemoveDuplicatesfromSortedListII.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;

TEST(case_1, content) {
    vector<int> vec = {1,2,3,3,4,4,5};
    vector<int> ans = {1,2,5};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_2, content) {
    vector<int> vec = {1};
    vector<int> ans = {1};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}

TEST(case_3, content) {
    vector<int> vec = {1,1};
    vector<int> ans = {};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}

TEST(case_4, content) {
    vector<int> vec = {1,1,2,2,2,3};
    vector<int> ans = {3};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_5, content) {
    vector<int> vec = {-1,1,1,2,2,2,3,3,3,3};
    vector<int> ans = {-1};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_6, content) {
    vector<int> vec = {1,1,1,2,2,2,3,4};
    vector<int> ans = {3,4};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_11, content) {
    vector<int> vec = {1,2,3,3,4,4,5};
    vector<int> ans = {1,2,5};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates1(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_21, content) {
    vector<int> vec = {1};
    vector<int> ans = {1};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates1(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}

TEST(case_31, content) {
    vector<int> vec = {1,1};
    vector<int> ans = {};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates1(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}

TEST(case_41, content) {
    vector<int> vec = {1,1,2,2,2,3};
    vector<int> ans = {3};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates1(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_51, content) {
    vector<int> vec = {-1,1,1,2,2,2,3,3,3,3};
    vector<int> ans = {-1};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates1(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_61, content) {
    vector<int> vec = {1,1,1,2,2,2,3,4};
    vector<int> ans = {3,4};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates1(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_11, content1) {
    vector<int> vec = {1,2,3,3,4,4,5};
    vector<int> ans = {1,2,5};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_21, content1) {
    vector<int> vec = {1};
    vector<int> ans = {1};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}

TEST(case_31, content1) {
    vector<int> vec = {1,1};
    vector<int> ans = {};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}

TEST(case_41, content1) {
    vector<int> vec = {1,1,2,2,2,3};
    vector<int> ans = {3};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_51, content1) {
    vector<int> vec = {-1,1,1,2,2,2,3,3,3,3};
    vector<int> ans = {-1};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}


TEST(case_61, content1) {
    vector<int> vec = {1,1,1,2,2,2,3,4};
    vector<int> ans = {3,4};
    ListNode * pO = createLinkList(vec);
    ListNode * p1 = createLinkList(ans);
    ListNode * pAns = deleteDuplicates2(pO);
    printList(pAns);
    EXPECT_EQ(ListValEqual(p1, pAns), true);
    freeLinkList(pAns);
    freeLinkList(p1);
}