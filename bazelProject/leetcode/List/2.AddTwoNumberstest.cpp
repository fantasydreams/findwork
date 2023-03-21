#include "2.AddTwoNumbers.h"
#include "gtest/gtest.h"

//一样长
TEST(case_1,content)
{
    std::vector<int> a = {2,4,3};
    std::vector<int> b = {5,6,4};
    std::vector<int> sum = {7,0,8};
	ListNode * lista = createLinkList(a);
    ListNode * listb = createLinkList(b);
    ListNode * listsum = addTwoNumbers1(lista, listb);
    ListNode * listsum2 = addTwoNumbers2(lista, listb);
    std::vector<int> realsum = convertLink2Vector(listsum);
    std::vector<int> realsum2 = convertLink2Vector(listsum2);
    EXPECT_EQ(sum, realsum);
    EXPECT_EQ(sum, realsum2);
    // freeLinkList(listsum2);
    freeLinkList(listb);
    freeLinkList(listsum);
}

//不一样长
TEST(case_2,content)
{
    std::vector<int> a = {4,3};
    std::vector<int> b = {5,6,4};
    std::vector<int> sum = {9,9,4};
	ListNode * lista = createLinkList(a);
    ListNode * listb = createLinkList(b);
    ListNode * listsum = addTwoNumbers1(lista, listb);
    ListNode * listsum2 = addTwoNumbers2(lista, listb);
    std::vector<int> realsum = convertLink2Vector(listsum);
    std::vector<int> realsum2 = convertLink2Vector(listsum2);
    EXPECT_EQ(sum, realsum);
    EXPECT_EQ(sum, realsum2);
    // freeLinkList(listsum2);
    freeLinkList(listb);
    freeLinkList(listsum);
}

//存在空串
TEST(case_3,content)
{
    std::vector<int> a = {};
    std::vector<int> b = {5,6,4};
    std::vector<int> sum = {5,6,4};
	ListNode * lista = createLinkList(a);
    ListNode * listb = createLinkList(b);
    ListNode * listsum = addTwoNumbers1(lista, listb);
    ListNode * listsum2 = addTwoNumbers2(lista, listb);
    std::vector<int> realsum = convertLink2Vector(listsum);
    std::vector<int> realsum2 = convertLink2Vector(listsum2);
    EXPECT_EQ(sum, realsum);
    EXPECT_EQ(sum, realsum2);
    // freeLinkList(listsum2);
    freeLinkList(listb);
    freeLinkList(listsum);
}


//全是空串
TEST(case_4,content)
{
    std::vector<int> a = {};
    std::vector<int> b = {};
    std::vector<int> sum = {0};
	ListNode * lista = createLinkList(a);
    ListNode * listb = createLinkList(b);
    ListNode * listsum = addTwoNumbers1(lista, listb);
    ListNode * listsum2 = addTwoNumbers2(lista, listb);
    std::vector<int> realsum = convertLink2Vector(listsum);
    std::vector<int> realsum2 = convertLink2Vector(listsum2);
    EXPECT_EQ(sum, realsum);
    EXPECT_EQ(sum, realsum2);
    // freeLinkList(listsum2);
    freeLinkList(listb);
    freeLinkList(listsum);
}


TEST(case_5,content)
{
    std::vector<int> a = {9,9,9,9,9,9,9};
    std::vector<int> b = {9,9,9,9};
    std::vector<int> sum = {8,9,9,9,0,0,0,1};
	ListNode * lista = createLinkList(a);
    ListNode * listb = createLinkList(b);
    ListNode * listsum = addTwoNumbers1(lista, listb);
    ListNode * listsum2 = addTwoNumbers2(lista, listb);
    std::vector<int> realsum = convertLink2Vector(listsum);
    std::vector<int> realsum2 = convertLink2Vector(listsum2);
    EXPECT_EQ(sum, realsum);
    EXPECT_EQ(sum, realsum2);
    // freeLinkList(listsum2);
    freeLinkList(listb);
    freeLinkList(listsum);
}

TEST(case_6,content)
{
    std::vector<int> a = {2,4,9};
    std::vector<int> b = {5,6,4,9};
    std::vector<int> sum = {7,0,4,0,1};
	ListNode * lista = createLinkList(a);
    ListNode * listb = createLinkList(b);
    ListNode * listsum = addTwoNumbers1(lista, listb);
    ListNode * listsum2 = addTwoNumbers2(lista, listb);
    std::vector<int> realsum = convertLink2Vector(listsum);
    std::vector<int> realsum2 = convertLink2Vector(listsum2);
    EXPECT_EQ(sum, realsum);
    EXPECT_EQ(sum, realsum2);
    // freeLinkList(listsum2);
    freeLinkList(listb);
    freeLinkList(listsum);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}