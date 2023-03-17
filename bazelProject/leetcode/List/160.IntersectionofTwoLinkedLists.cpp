#include "160.IntersectionofTwoLinkedLists.h"



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