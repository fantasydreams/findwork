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

ListNode* removeNthFromEnd1(ListNode* head, int n) {
    if(head == nullptr) {
        return nullptr;
    }

    ListNode oHead, *pslow = &oHead, *pfast = pslow;
    oHead.next = head;
    while(n > 0 && pfast && pfast->next){
        pfast = pfast->next;
        --n;
    }

    if(n) {
        return head;
    }

    while(pfast && pfast->next) {
        pfast = pfast->next;
        pslow = pslow->next;
    }

    ListNode * pdel = pslow->next;
    pslow->next = pdel->next;
    delete pdel;

    return oHead.next;
}