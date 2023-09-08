#include "83.RemoveDuplicatesfromSortedList.h"
#include "linkcomm.h"
#include <vector>

ListNode* deleteDuplicates(ListNode* head) {
    ListNode oHead, *tmp = &oHead, *pNext;
    oHead.next = head;
    std::vector<bool> hash(205, false);
    int base = 100;
    while(tmp && tmp->next) {
        if(hash[tmp->next->val + base] == false) {
            hash[tmp->next->val + base] = true;
            tmp = tmp -> next;
        }else {
            pNext = tmp -> next;
            tmp -> next = pNext -> next;
            delete pNext;
        }
    }

    return oHead.next;
}

ListNode* deleteDuplicates1(ListNode* head) {
    ListNode *tmp = head, *pNext;
    while(tmp && tmp->next) {
        if(tmp->val == tmp->next->val) {
            pNext = tmp->next;
            tmp->next = pNext->next;
            delete pNext;
        }else {
            tmp = tmp -> next;
        }
    }

    return head;
}


ListNode* deleteDuplicates2(ListNode* head) {
    if(head == nullptr) {
        return head;
    }

    ListNode oHead;
    ListNode* pTail = &oHead;
    pTail->next = head;
    pTail = pTail->next;
    head = head->next;
    while(head) {
        if(pTail->val != head->val) {
            pTail->next = head;
            pTail = pTail->next;
            head = head ->next;
        }else {
            ListNode* pNode = head;
            head = head->next;
            delete pNode;
        }
    }
    pTail->next = nullptr;
    return oHead.next;
}


ListNode* deleteDuplicates3(ListNode* head) {
    ListNode* pTail = head;
    while(pTail && pTail->next) {
        if(pTail->val != pTail->next->val) {
            pTail = pTail -> next;
        }else {
            ListNode* pNode = pTail->next;
            pTail->next = pTail->next->next;
            delete pNode;
        }
    }
    return head;
}