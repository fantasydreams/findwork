#include "203.RemoveLinkedListElements.h"
#include "linkcomm.h"

ListNode* removeElements(ListNode* head, int val) {
    ListNode oHead;
    ListNode* pPre = &oHead;
    while(head) {
        if(head->val != val) {
            pPre->next = head;
            head = head->next;
            pPre = pPre->next;
        }else {
            ListNode *pNode = head;
            head = head->next;
            delete pNode;
        }
    }
    pPre->next = nullptr;
    return oHead.next;
}