#include "21.MergeTwoSortedLists.h"
#include "linkcomm.h"

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode head, *tmp = &head;
    while(list1 && list2) {
        if(list1 -> val < list2 -> val) {
            tmp->next = list1;
            list1 = list1->next;
        }else {
            tmp->next = list2;
            list2 = list2->next;
        }
        tmp = tmp->next;
    }

    if(list1) {
        tmp -> next = list1;
    }

    if(list2) {
        tmp -> next = list2;
    }

    return head.next;
}


ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr || list2 == nullptr) {
        return list1 ? list1 : list2;
    }

    ListNode oHead;
    ListNode* pNode = &oHead;
    while(list1 && list2) {
        if(list1->val < list2->val) {
            pNode->next = list1;
            list1 = list1->next;    
        }else {
            pNode->next = list2;
            list2 = list2->next;
        }

        pNode = pNode->next;
    }

    pNode->next = list1 ? list1 : list2;
    return oHead.next;
}