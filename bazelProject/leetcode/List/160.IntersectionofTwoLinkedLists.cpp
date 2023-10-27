#include "160.IntersectionofTwoLinkedLists.h"
#include "linkcomm.h"



ListNode *getIntersectionNode(ListNode* headA, ListNode * headB) {
    size_t lenA = getLinkLen(headA), lenB = getLinkLen(headB);
    ListNode * lLong = lenA > lenB ? headA : headB;
    ListNode * lShort = lenA > lenB ? headB : headA;
    size_t diff = lenA > lenB ? lenA - lenB : lenB - lenA;
    while(diff--) {
        lLong = lLong -> next;
    }

    while(lLong && lShort && lLong != lShort) {
        lLong = lLong -> next;
        lShort = lShort -> next;
    }

    return lLong;
}


ListNode *getIntersectionNodeTwoPointer(ListNode* headA, ListNode *headB) {
    ListNode * node1 = headA, *node2 = headB;
    while(node1 != node2 ) {
        if(node1 == nullptr) {
            node1 = headB;
        }else {
            node1 = node1 -> next;
        }

        if(node2 == nullptr) {
            node2 = headA;
        }else {
            node2 = node2 -> next;
        }
    }

    return node1;
}


ListNode *getIntersectionNodeLen(ListNode* headA, ListNode * headB) {
    if(headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    int lenA = getLinkLen(headA), lenB = getLinkLen(headB);
    int longLen = lenA, shortLen = lenB;
    ListNode * pLong = headA, *pShort = headB;
    if(lenA < lenB) {
        std::swap(longLen, shortLen);
        std::swap(pLong, pShort);
    }

    int diff = longLen - shortLen;
    while(diff) {
        pLong = pLong->next;
        --diff;
    }

    while(pLong && pShort && pLong != pShort) {
        pLong = pLong->next;
        pShort = pShort->next;
    }

    return pLong;
}


ListNode *getIntersectionNodeTwoPointer1(ListNode* headA, ListNode * headB) {
    if(headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    ListNode* pA = headA, *pB = headB;
    while(pA != pB) {
        if(pA) {
            pA = pA->next;
        }else {
            pA = headB;
        }

        if(pB) {
            pB = pB->next;
        }else {
            pB = headA;
        }
    }

    return pA;
}