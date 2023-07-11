#include "234.PalindromeLinkedList.h"
#include "gtest/gtest.h"


//一样长
TEST(case_1,content)
{
    std::vector<int> a = {1,2,0};
    ListNode * head = createLinkList(a);
    bool ans = false;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}


TEST(case_2,content)
{
    std::vector<int> a = {};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}

TEST(case_3,content)
{
    std::vector<int> a = {1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}

TEST(case_4,content)
{
    std::vector<int> a = {1,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}

TEST(case_5,content)
{
    std::vector<int> a = {1,1,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}

TEST(case_6,content)
{
    std::vector<int> a = {1,1,2};
    ListNode * head = createLinkList(a);
    bool ans = false;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}

TEST(case_7,content)
{
    std::vector<int> a = {1,2,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}

TEST(case_8,content)
{
    std::vector<int> a = {1,2,2,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}

TEST(case_9,content)
{
    std::vector<int> a = {1,2,1,2};
    ListNode * head = createLinkList(a);
    bool ans = false;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}


TEST(case_10,content)
{
    std::vector<int> a = {1,2,3,2,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}

TEST(case_11,content)
{
    std::vector<int> a = {1,2,3,2,2};
    ListNode * head = createLinkList(a);
    bool ans = false;
    EXPECT_EQ(isPalindrome(head), ans);
    freeLinkList(head);
}


TEST(case_22,content)
{
    std::vector<int> a = {1,2,0};
    ListNode * head = createLinkList(a);
    bool ans = false;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}


TEST(case_12,content)
{
    std::vector<int> a = {};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}

TEST(case_13,content)
{
    std::vector<int> a = {1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}

TEST(case_14,content)
{
    std::vector<int> a = {1,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}

TEST(case_15,content)
{
    std::vector<int> a = {1,1,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}

TEST(case_16,content)
{
    std::vector<int> a = {1,1,2};
    ListNode * head = createLinkList(a);
    bool ans = false;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}

TEST(case_17,content)
{
    std::vector<int> a = {1,2,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}

TEST(case_18,content)
{
    std::vector<int> a = {1,2,2,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}

TEST(case_19,content)
{
    std::vector<int> a = {1,2,1,2};
    ListNode * head = createLinkList(a);
    bool ans = false;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}


TEST(case_20,content)
{
    std::vector<int> a = {1,2,3,2,1};
    ListNode * head = createLinkList(a);
    bool ans = true;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}

TEST(case_21,content)
{
    std::vector<int> a = {1,2,3,2,2};
    ListNode * head = createLinkList(a);
    bool ans = false;
    EXPECT_EQ(isPalindrome1(head), ans);
    freeLinkList(head);
}