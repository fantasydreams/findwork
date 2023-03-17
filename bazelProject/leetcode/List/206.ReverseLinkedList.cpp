#include "206.ReverseLinkedList.h"

ListNode* reverseList(ListNode* head) {
    ListNode ohead, *tmp;
    while(head) {
        tmp = head->next;
        head->next = ohead.next;
        ohead.next = head;
        head = tmp;
    }

    return ohead.next;
}