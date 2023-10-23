#include "142.LinkedListCycleII.h"
#include "linkcomm.h"
#include <cstddef>
#include <unordered_set>

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

ListNode *detectCycle1(ListNode *head) {
    if(head == nullptr) {
        return nullptr;
    }

    ListNode * pSlow = head, *pFast = head, *pTmp = nullptr;
    do{
        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast) {
            pFast = pFast->next;
        }

        if(pFast && pFast == pSlow) {
            pTmp = pSlow;
            break;
        }
    }while(pSlow && pFast);

    if(pTmp == nullptr) {
        return nullptr;
    }

    ListNode* pCur = head;
    while(pCur != pTmp) {
        pCur = pCur->next;
        pTmp = pTmp->next;
    }

    return pCur;
}


ListNode *detectCycleHash(ListNode *head) {
    if(head == nullptr) {
        return nullptr;
    }

    std::unordered_set<ListNode*> hash;
    hash.insert(head);
    ListNode* pCur = head->next;
    while(pCur) {
        if(hash.count(pCur)) {
            return pCur;
        }
        hash.insert(pCur);
        pCur = pCur->next;
    }

    return nullptr;
}