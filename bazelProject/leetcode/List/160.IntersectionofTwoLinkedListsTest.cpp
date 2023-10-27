#include "160.IntersectionofTwoLinkedLists.h"
#include "gtest/gtest.h"


//一样长
TEST(case_1,content)
{
    std::vector<int> a = {1,2,0};
    std::vector<int> b = {5,4};
    std::vector<int> comm = {3,2,1};
    ListNode * pa = nullptr, *pb = nullptr;
    createIntersection(a,b, comm, pa, pb);
    // printList(pa);
    // printList(pb);
    
    ListNode * cpc = getIntersectionNode(pa, pb);
    EXPECT_EQ((bool)cpc, true);
    EXPECT_EQ(cpc->val, 3);

    cpc = getIntersectionNodeTwoPointer(pa, pb);
    EXPECT_EQ((bool)cpc, true);
    EXPECT_EQ(cpc->val, 3);

    cpc = getIntersectionNodeLen(pa, pb);
    EXPECT_EQ((bool)cpc, true);
    EXPECT_EQ(cpc->val, 3);

    cpc = getIntersectionNodeTwoPointer1(pa, pb);
    EXPECT_EQ((bool)cpc, true);
    EXPECT_EQ(cpc->val, 3);
}


//一样长
TEST(case_2, content)
{
    std::vector<int> a = {};
    std::vector<int> b = {5,4};
    std::vector<int> comm = {3,2,1};
    ListNode * pa = nullptr, *pb = nullptr;
    createIntersection(a,b, comm, pa, pb);
    // printList(pa);
    // printList(pb);
    
    ListNode * cpc = getIntersectionNode(pa, pb);
    EXPECT_EQ((bool)cpc, true);
    EXPECT_EQ(cpc->val, 3);

    cpc = getIntersectionNodeTwoPointer(pa, pb);
    EXPECT_EQ((bool)cpc, true);
    EXPECT_EQ(cpc->val, 3);

    cpc = getIntersectionNodeLen(pa, pb);
    EXPECT_EQ((bool)cpc, true);
    EXPECT_EQ(cpc->val, 3);

    cpc = getIntersectionNodeTwoPointer1(pa, pb);
    EXPECT_EQ((bool)cpc, true);
    EXPECT_EQ(cpc->val, 3);
}

TEST(case_3, content)
{
    std::vector<int> a = {123};
    std::vector<int> b = {5,4};
    std::vector<int> comm = {};
    ListNode * pa = nullptr, *pb = nullptr;
    createIntersection(a,b, comm, pa, pb);
    // printList(pa);
    // printList(pb);
    
    ListNode * cpc = getIntersectionNode(pa, pb);
    EXPECT_EQ((bool)cpc, false);
    // EXPECT_EQ(cpc->val, 3);

    cpc = getIntersectionNodeTwoPointer(pa, pb);
    EXPECT_EQ((bool)cpc, false);

    cpc = getIntersectionNodeLen(pa, pb);
    EXPECT_EQ((bool)cpc, false);
    // EXPECT_EQ(cpc->val, 3);

    cpc = getIntersectionNodeTwoPointer1(pa, pb);
    EXPECT_EQ((bool)cpc, false);
    // EXPECT_EQ(cpc->val, 3);

}