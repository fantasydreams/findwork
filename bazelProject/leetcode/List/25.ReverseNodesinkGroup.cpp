#include "25.ReverseNodesinkGroup.h"
#include "linkcomm.h"

void reverse(ListNode* pPre, ListNode* pCur, ListNode* pKth) {
    ListNode* pHead = pCur, *pKthNext = pKth->next;
    pCur = pCur->next;
    pHead->next = pKthNext;
    while(pCur != pKthNext) {
        ListNode* pTmp = pCur->next;
        pCur->next = pHead;
        pHead = pCur;
        pCur = pTmp;
    }

    pPre->next = pHead;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(k <= 1) {
        return head;
    }

    ListNode oHead, *pPre = &oHead, *pCur = head;
    oHead.next = head;
    while(pCur) {
        ListNode * pKth = pCur;
        int i = 1;
        while(i < k && pKth && pKth->next) {
            pKth = pKth->next;
            ++i;
        }

        if(i != k) {
            break;
        }else {
            ListNode* pNext = pKth->next;
            reverse(pPre, pCur, pKth);
            pPre = pCur;
            pCur = pNext;
        }
    }

    return oHead.next;
}