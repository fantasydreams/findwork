#include "2.AddTwoNumbers.h"


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