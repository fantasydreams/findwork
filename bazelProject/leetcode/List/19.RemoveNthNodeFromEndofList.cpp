#include "19.RemoveNthNodeFromEndofList.h"
#include "linkcomm.h"
#include <cstddef>

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


ListNode* removeNthFromEnd2(ListNode* head, int n) {
    ListNode oHead; oHead.next = head;
    ListNode* pSlow = &oHead, *pFast = pSlow;
    while(pFast && n--) {
        pFast = pFast->next;
    }

    if(pFast == nullptr) {
        return head;
    }

    while(pFast && pFast->next) {
        pSlow = pSlow->next;
        pFast = pFast->next;
    }

    ListNode* pNode = pSlow->next;
    pSlow->next = pNode->next;
    delete pNode;
    return oHead.next;
}