#include "19.RemoveNthNodeFromEndofList.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode oHead, *slow = &oHead, *fast = slow;
    oHead.next = head;
    while(n--) {
        fast = fast -> next;
    }

    while(fast && fast -> next) {
        fast = fast -> next;
        slow = slow -> next;
    }

    ListNode * del = slow -> next;
    slow -> next = del -> next;
    delete del;
    return oHead.next;
}