#include "142.LinkedListCycleII.h"

ListNode *detectCycle(ListNode *head)
{
    if(!head) {
        return NULL;
    }

    ListNode * pFast = head, * pSlow = head;
    ListNode * pTmp = NULL;
    do
    {
        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast) {
            pFast = pFast->next;
        }

        if(pFast && (pFast == pSlow)) 
        {
            pTmp = pFast;
            break;
        }
    }while(pFast && pSlow);
    
    if(!pTmp) {
        return NULL;
    }

    ListNode * pCur = head;
    while(pCur != pTmp)
    {
        pCur = pCur->next;
        pTmp = pTmp->next;
    }

    return pCur;
}