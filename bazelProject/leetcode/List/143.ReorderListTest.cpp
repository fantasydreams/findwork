#include "143.ReorderList.h"
#include "gtest/gtest.h"

TEST(case_1,content)
{
    std::vector<int> linkvec = {1,2,3,4,5};
    std::vector<int> con = {1,5,2,4,3};
	ListNode * link = createLinkList(linkvec);
    reorderList(link);
    EXPECT_EQ(convertLink2Vector(link), con);
    freeLinkList(link);
}

TEST(case_2,content)
{
    std::vector<int> linkvec = {1,2,3,4};
    std::vector<int> con = {1,4,2,3};
	ListNode * link = createLinkList(linkvec);
    reorderList(link);
    EXPECT_EQ(convertLink2Vector(link), con);
    freeLinkList(link);
}

TEST(case_3,content)
{
    std::vector<int> linkvec = {1,2,3,4,5};
    std::vector<int> con = {1,5,2,4,3};
	ListNode * link = createLinkList(linkvec);
    reorderList1(link);
    EXPECT_EQ(convertLink2Vector(link), con);
    freeLinkList(link);
}

TEST(case_4,content)
{
    std::vector<int> linkvec = {1,2,3,4};
    std::vector<int> con = {1,4,2,3};
	ListNode * link = createLinkList(linkvec);
    reorderList1(link);
    EXPECT_EQ(convertLink2Vector(link), con);
    freeLinkList(link);
}

TEST(case_5,content)
{
    std::vector<int> linkvec = {1,2,3,4,5};
    std::vector<int> con = {1,5,2,4,3};
	ListNode * link = createLinkList(linkvec);
    reorderList2(link);
    EXPECT_EQ(convertLink2Vector(link), con);
    freeLinkList(link);
}

TEST(case_6,content)
{
    std::vector<int> linkvec = {1,2,3,4};
    std::vector<int> con = {1,4,2,3};
	ListNode * link = createLinkList(linkvec);
    reorderList2(link);
    EXPECT_EQ(convertLink2Vector(link), con);
    freeLinkList(link);
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}