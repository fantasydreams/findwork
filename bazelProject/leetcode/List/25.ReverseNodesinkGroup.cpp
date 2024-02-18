#include "25.ReverseNodesinkGroup.h"
#include "linkcomm.h"
#include <cstddef>

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


ListNode* reversekTh(ListNode* pList, int k, ListNode*& pkthNext) {
    ListNode* pHead = pList, *pTail = nullptr;
    while (pList && k--) {
        ListNode* pCur = pList;
        pList = pList->next;
        pCur->next = pTail;
        pTail = pCur;
        pHead = pCur;
    }

    ListNode* pTmpHead = pHead; pTail = nullptr;
    if(k > 0) {
        while(pTmpHead) {
            ListNode* pCurNode = pTmpHead;
            pTmpHead = pTmpHead->next;
            pCurNode->next = pTail;
            pTail = pCurNode;
            pHead = pCurNode;
        }
    }

    pkthNext = pList; 
    return pHead;
}


ListNode* reverseKGroup1(ListNode* head, int k) {
    if(k <= 1 || head == nullptr) {
        return head;
    }

    ListNode *pAnsHead = nullptr, *pPreTail = nullptr;
    while(head) {
        ListNode* pTail = head;
        ListNode* pkGroupHead = reversekTh(head, k, head);
        if(pAnsHead == nullptr) {
            pAnsHead = pkGroupHead;
        }

        if(pPreTail != nullptr) {
            pPreTail->next = pkGroupHead;
        }
        pPreTail = pTail;
    }

    return pAnsHead;
}


ListNode* ReverseKthGroup(ListNode* pHead, int k, ListNode* & pKthNext) {
    ListNode* pNewHead = nullptr;
    int i = 0;
    while(pHead && i < k) {
        ListNode* pNode = pHead;
        pHead = pHead->next;
        pNode->next = pNewHead;
        pNewHead = pNode;
        ++i;
    }
    
    if(i < k) { // 翻转
        ListNode* pTmp = pNewHead;
        pNewHead = nullptr;
        while(pTmp) {
            ListNode* pNode = pTmp;
            pTmp = pTmp->next;
            pNode->next = pNewHead;
            pNewHead = pNode;
        }
    }

    pKthNext = pHead;
    return pNewHead;
}

ListNode* reverseKGroup2(ListNode* head, int k) {
    if(k <= 1 || head == nullptr) {
        return head;
    }

    ListNode* pAnsHead = nullptr, *pPreTail = nullptr;
    while(head) {
        ListNode *pTail = head;
        ListNode *pKthGroupHead = ReverseKthGroup(head, k, head);
        if(pAnsHead == nullptr) {
            pAnsHead = pKthGroupHead;
        }
        if(pPreTail != nullptr) {
            pPreTail->next = pKthGroupHead;
        }
        pPreTail = pTail;
    }

    return pAnsHead;
}