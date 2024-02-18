#include "linkcomm.h"
#include <unordered_set>

bool hasCycle(ListNode *head) {
    if(head == nullptr) {
        return false;
    }

    ListNode* pSlow = head, *pFast = head->next;
    while(pSlow && pFast) {
        if(pSlow == pFast) {
            return true;
        }
        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast) {
            pFast = pFast->next;
        }
    }

    return false;
}

bool hasCycle1(ListNode *head) {
    if(!head) return false;
    std::unordered_set<ListNode*> set;
    while(head){
        if(set.count(head)) {
            return true;
        }
        set.insert(head);
        head=head->next;
    }
    
    return false;
}


bool hasCycle2(ListNode *head) {
    if(head == nullptr) {
        return false;
    }

    ListNode* pSlow = head, *pFast = head->next;
    while(pFast) {
        if(pSlow == pFast) {
            return true;
        }

        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast) {
            pFast = pFast->next;
        }
    }

    return false;
}