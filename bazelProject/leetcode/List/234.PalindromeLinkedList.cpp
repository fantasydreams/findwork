#include "234.PalindromeLinkedList.h"

bool isPalindrome(ListNode* head) {
    if(head == nullptr) {
        return true;
    }

    ListNode * fast = head, * slow = head;
    while(fast && fast->next && fast -> next ->next) {
        slow = slow->next;
        fast = fast->next;
        if(fast) {
            fast = fast -> next;
        }
    }

    //slow后面的进行反转
    ListNode * left = slow;
    if(slow) {
        ListNode * tmp = slow -> next, *next;
        left ->next = nullptr;
        while(tmp) {
            next = tmp->next;
            tmp -> next = left -> next;
            left -> next = tmp;
            tmp = next;
        }
    }

    // printList(head);
    if(left) {
        left = left->next;
    }
    
    while(head && left) {
        if(head->val != left -> val) {
            return false;
        }
        head = head->next;
        left = left->next;
    }

    return true;
}