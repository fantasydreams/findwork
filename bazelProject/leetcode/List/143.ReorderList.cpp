#include "143.ReorderList.h"
#include "linkcomm.h"
#include <cstddef>


// 拆成两半，后半部分反转，然后依次按顺序合起来
void reorderList(ListNode* head)
{
    if(!head) return;
    uint32_t total = 0;
    ListNode * tmp = head;
    while(tmp){
        ++total;
        tmp = tmp->next;
    }

    if(total == 1){
        return;
    }

    uint32_t half = total / 2 + total % 2;
    ListNode * halfpre = head; 
    tmp = head->next;
    halfpre->next = nullptr;

    ListNode * rehalfpost = nullptr;
    for(uint32_t i = 1; tmp; ++i)
    {
        ListNode * node = tmp;
        tmp = tmp->next;
        node->next = nullptr;
        if(i < half)
        {
            halfpre->next = node;
            halfpre = node;
        }else
        {
            node->next = rehalfpost;
            rehalfpost = node;
        }
    }

    tmp = head;
    while(tmp && rehalfpost)
    {
        ListNode * node = tmp->next;
        ListNode * insert = rehalfpost;
        rehalfpost = rehalfpost->next;
        tmp->next = insert;
        insert->next = node;
        tmp = node;
    }
}


//快慢指针，满指针一定是分成链表分成两部分的第二部分的头指针，
//奇数的情况中间的那个元素在第一部分，偶数的时候两部分元素个数相等
void reorderList1(ListNode* head) 
{
    if(!head || head->next == nullptr) return;
    ListNode * fast = head, *slow = head, *pre;
    while(fast)
    {
        fast = fast->next;
        if(fast) fast=fast->next;
        pre = slow;
        slow = slow->next;
    }
    
    pre->next = nullptr;
    
    ListNode * reverse = nullptr;
    while(slow)
    {
        ListNode * node = slow;
        slow = slow->next;
        node->next = reverse;
        reverse = node;
    }
    
    ListNode * tmp = head;
    while(reverse)
    {
        ListNode * node = reverse;
        reverse = reverse->next;
        node->next = tmp->next;
        tmp->next = node;
        tmp=node->next;
    }
    
}


void reorderList2(ListNode* head) {
    if(!head || head->next == nullptr) {
        return;
    }

    ListNode oHead;
    ListNode* fast = head, *slow = head;
    ListNode* pre = nullptr;
    while(fast) {
        pre = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast) {
            fast = fast->next;
        }
    };

    pre->next = nullptr;
    ListNode* reverse = nullptr;
    while(slow) {
        ListNode* node = slow;
        slow = slow->next;
        node->next = reverse;
        reverse = node;
    }

    ListNode* tmp = head;
    while(reverse) {
        ListNode* node = reverse;
        reverse = reverse->next;
        node->next = tmp->next;
        tmp->next = node;
        tmp = node->next;
    }
}