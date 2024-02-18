#include "2.AddTwoNumbers.h"
#include "linkcomm.h"


ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) 
{
    ListNode * pListHead = nullptr, *pCurNode = nullptr;
    int carry = 0;
    while(l1 && l2)
    {
        int sum = l2->val + l1->val + carry;
        int val = sum % 10;
        carry = sum / 10;

        ListNode * pTmpNode = new ListNode(val);
        if(pListHead == nullptr){
            pListHead = pCurNode = pTmpNode;
        }else{
            pCurNode->next = pTmpNode;
            pCurNode = pTmpNode;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    ListNode * pTmpList = l2 == nullptr ? l1 : l2;
    while(pTmpList)
    {
        int val = pTmpList->val + carry;
        carry = val / 10;
        val %= 10;
        ListNode * pTmpNode = new ListNode(val);
        if(pListHead == nullptr){
            pListHead = pCurNode = pTmpNode;
        }else{
            pCurNode->next = pTmpNode;
            pCurNode = pTmpNode;
        }
        pTmpList = pTmpList->next;
    }

    if(carry)
    {
        ListNode * pTmpNode = new ListNode(carry);
        if(pListHead == nullptr){
            pListHead = pCurNode = pTmpNode;
        }else{
            pCurNode->next = pTmpNode;
            pCurNode = pTmpNode;
        }
    }

    if(pListHead == nullptr){
        pListHead = new ListNode(0);
    }

    return pListHead;
}




ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    ListNode* tmp1 = l1, * tmp2 = l2;
    while(tmp1 && tmp2) {
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    ListNode* pLong = tmp1 ? l1 : l2;
    ListNode* pShort = tmp1 ? l2 : l1;
    ListNode* pre = pLong;
    tmp1 = pLong, tmp2 = pShort;
    int carry = 0, sum = 0;
    while(tmp1 &&  tmp2) {
        sum = tmp1->val + tmp2->val + carry;
        tmp1->val = sum % 10;
        carry = sum / 10;

        pre = tmp1;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    while(tmp1 && carry) {
        pre = tmp1;
        sum = tmp1->val + carry;
        tmp1->val = sum % 10;
        carry = sum / 10;
        tmp1 = tmp1->next;
    }

    if(carry) {
        pre->next = new ListNode(carry);
    }

    if(pLong == nullptr) {
        return new ListNode(0);
    }

    return pLong;
}


ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
    ListNode* pTmp1 = l1, *pTmp2 = l2;
    while(pTmp1 && pTmp2) {
        pTmp1 = pTmp1 -> next;
        pTmp2 = pTmp2 -> next;
    }

    ListNode* pLong = pTmp1 ? l1 : l2;
    ListNode* pShort = pTmp1 ? l2 : l1;
    ListNode* pPre = pLong;
    pTmp1 = pLong, pTmp2 = pShort;
    int carry = 0;
    while(pTmp2) {
        int sum = pTmp1->val + pTmp2->val + carry;
        pTmp1->val = sum % 10;
        carry = sum / 10;
        pPre = pTmp1;
        pTmp1 = pTmp1->next;
        pTmp2 = pTmp2->next;
    }

    while(pTmp1 && carry) {
        int sum = pTmp1->val + carry;
        pTmp1->val = sum % 10;
        carry = sum / 10;
        pPre = pTmp1;
        pTmp1 = pTmp1->next;
    }

    if(carry) {
        pPre->next = new ListNode(carry);
    }

    if(pLong == nullptr) {
        pLong = new ListNode(0);
    }

    return pLong;
}