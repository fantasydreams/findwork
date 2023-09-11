#include "92.ReverseLinkedListII.h"
#include "linkcomm.h"

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode oLeft, oMid;
    oLeft.next = head;
    ListNode* pHead = &oLeft, *pMid = &oMid;
    int iCur = 1;
    while(iCur < left) {
        pHead = pHead->next;
        ++iCur;
    }

    ListNode* pMidTail = pHead->next;
    ListNode* pNode = pHead->next;
    while(iCur <= right) {
        ListNode* pTmp = pNode->next;
        pNode->next = pMid->next;
        pMid->next = pNode;
        pNode = pTmp;
        ++iCur;
    }

    pHead->next = oMid.next;
    pMidTail->next = pNode;
    return oLeft.next;
}