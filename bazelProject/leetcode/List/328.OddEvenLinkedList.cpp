#include "328.OddEvenLinkedList.h"

ListNode* oddEvenList(ListNode* head) {
    ListNode oHead, oEven, *pOdd = &oHead, *pEven = &oEven;
    int idx = 0;
    while(head) {
        ++idx;
        if(idx & 0x1) {
            pOdd->next = head;
            pOdd = pOdd -> next;
        }else {
            pEven->next = head;
            pEven = pEven->next;
        }
        head = head->next;
    }

    pEven->next = nullptr;
    pOdd->next = oEven.next;
    return oHead.next;
}