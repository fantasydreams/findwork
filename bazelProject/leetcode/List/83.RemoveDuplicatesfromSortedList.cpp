#include "83.RemoveDuplicatesfromSortedList.h"
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