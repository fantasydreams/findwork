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