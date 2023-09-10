#include "86.PartitionList.h"
#include "linkcomm.h"

ListNode* partition(ListNode* head, int x) {
    if(head == nullptr) {
        return head;
    }

    ListNode oHead, oGEHead;
    ListNode* pHead = &oHead, *pGEhead = &oGEHead;
    while(head) {
        if(head->val < x) {
            pHead->next = head;
            pHead = pHead->next;
        }else {
            pGEhead->next = head;
            pGEhead = pGEhead->next;
        }
        head = head->next;
    }

    pGEhead->next = nullptr;
    pHead->next = oGEHead.next;
    return oHead.next;
}