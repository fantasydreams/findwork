#include "61.RotateList.h"
#include "linkcomm.h"
#include <cstddef>

int getListLen(ListNode* head) {
    int ans = 0;
    while(head) {
        ++ans;
        head = head->next;
    }
    return ans;
}

ListNode* getListKthNode(ListNode* head, int k) {
    k-=1;
    
    while(head && k > 0) {
        head = head->next;
        --k;
    }
    
    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
    int len = getListLen(head);
    if(len == 1 || len == 0) {
        return head;
    }

    k = k % len;
    if(k > 0) {
        ListNode * pKth = getListKthNode(head, len - k);
        ListNode * pKthNext = pKth->next;
        pKth->next = nullptr;
        ListNode * pNewHead = pKthNext;
        while(pKthNext->next) {
            pKthNext = pKthNext->next;
        }
        pKthNext->next = head;
        return pNewHead;
    }

    return head;
}