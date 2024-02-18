#include "82.RemoveDuplicatesfromSortedListII.h"
#include "linkcomm.h"
#include <cinttypes>
#include <cstddef>

ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) {
        return head;
    }

    ListNode oHead;
    ListNode * pTail = &oHead;
    ListNode * pPre = nullptr;
    bool bDel = false;
    ListNode oDel;
    ListNode* pDel = &oDel;
    while(head) {
        if(head->next) {
            if((pPre == nullptr && head->val != head->next->val) || 
                (pPre != nullptr && pPre->val != head->val && head->next->val != head->val)) {
                    pTail->next = head;
                    pTail = pTail->next;
            }else {
                pDel->next = head;
                pDel = pDel->next;
            }
        }else {
            if(pPre == nullptr || pPre->val != head->val) {
                pTail->next = head;
                pTail = pTail->next;
            } else {
                pDel->next = head;
                pDel = pDel->next;
            } 
        }

        pPre = head;
        head = head->next;
    }

    pTail->next = nullptr;
    pDel->next = nullptr;
    pDel = oDel.next;
    while(pDel) {
        ListNode * pNode = pDel;
        pDel = pDel->next;
        delete pNode;
    }

    return oHead.next;
}



ListNode* deleteDuplicates1(ListNode* head) {
    ListNode oHead;
    ListNode* pTail = &oHead;
    int iPreVal = INT_MIN;
    while(head) {
        if((iPreVal != head->val) && (head->next == nullptr || head->next->val != head->val)) {
            pTail->next = head;
            pTail = pTail->next;
            iPreVal = head->val;
            head = head->next;
        }else {
            ListNode* pNode = head;
            iPreVal = head->val;
            head = head->next;
            delete pNode;
        }
    }

    pTail->next = nullptr;
    return oHead.next;
}


ListNode* deleteDuplicates2(ListNode* head) {
    if(head == nullptr) {
        return head;
    }

    ListNode oHead(head->val - 1);
    ListNode* pNode  = &oHead;
    int iPreVal = oHead.val;
    while(head) {
        if(iPreVal != head->val && (head->next == nullptr || head->next->val != head->val)) {
            pNode->next = head;
            head = head->next;
            pNode = pNode->next;            
            iPreVal = pNode->val;
        }else {
            ListNode* pNode1 = head;
            iPreVal = head->val;
            head = head->next;
            delete pNode1;
        }
    }

    pNode->next = nullptr;
    return oHead.next;
}