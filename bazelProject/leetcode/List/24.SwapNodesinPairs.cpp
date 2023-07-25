#include "24.SwapNodesinPairs.h"

ListNode* swapPairs(ListNode* head) {
    ListNode oHead, *pre = &oHead, *tmp = head, *cur;
    pre->next = head;
    while(tmp && tmp -> next) {
        cur = tmp -> next;
        tmp -> next = cur -> next;
        cur -> next = tmp;

        pre -> next = cur;
        pre = tmp;
        tmp = tmp -> next;
    }

    return oHead.next;
}


void swapAdjacent(ListNode * pre, ListNode * mid, ListNode* next) {
    ListNode* pTmp = next->next;
    next->next = mid;
    mid->next = pTmp;
    pre->next = next;
}

ListNode* swapPairs1(ListNode* head) {
    ListNode oHead, *pre = &oHead, *cur = head;
    oHead.next = head;
    while(cur && cur->next) {
        swapAdjacent(pre, cur, cur->next);
        pre = pre->next->next;
        cur = pre->next;
    }

    return oHead.next;
}