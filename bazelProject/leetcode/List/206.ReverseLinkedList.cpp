#include "206.ReverseLinkedList.h"
#include "linkcomm.h"

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



ListNode* reverseList1(ListNode* head) {
    ListNode oHead;
    while(head) {
        ListNode * pNode = head;
        head = head->next;
        pNode->next = oHead.next;
        oHead.next = pNode;
    }

    return oHead.next;
}